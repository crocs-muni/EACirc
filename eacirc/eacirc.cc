#include "eacirc.h"
#include "statistics.h"
#include "version.h"
#include <core/logger.h>
#include <core/random.h>
#include <fstream>
#include <pcg/pcg_random.hpp>

#include "circuit/backend.h"
#include "streams.h"
#include "core/stream.h"
#include "eacirc/streams.h"

static std::ifstream open_config_file(std::string path) {
    std::ifstream file(path);
    if (!file.is_open())
        throw std::runtime_error("can't open config file " + path);
    return file;
}

eacirc::eacirc(std::string config)
    : eacirc(open_config_file(config)) {}

eacirc::eacirc(json const& config)
    : _config(config)
    , _seed(seed::create(config.at("seed")))
    , _num_of_epochs(config.at("num-of-epochs"))
    , _significance_level(config.at("significance-level"))
    , _tv_size(config.at("tv-size"))
    , _tv_count(config.at("tv-count")) {
    logger::info() << "eacirc framework version: " << VERSION_TAG << std::endl;
    logger::info() << "current date: " << logger::date() << std::endl;
    logger::info() << "using seed: " << std::string(_seed) << std::endl;

    seed_seq_from<pcg32> main_seeder(_seed);

    {
        _stream_a = make_stream(config.at("stream-a"), main_seeder, _tv_size);
        _stream_b = make_stream(config.at("stream-b"), main_seeder, _tv_size);
    }

    {
        std::string backend_type = config.at("backend").at("type");
        if (backend_type == "circuit")
            _backend = circuit::create_backend(_tv_size, config.at("backend"), main_seeder);
        else
            throw std::runtime_error("no backend named [" + backend_type + "] is available");
    }
}

void eacirc::run() {
    std::vector<double> pvalues;
    pvalues.reserve(_num_of_epochs);

    dataset a{_tv_size, _tv_count};
    dataset b{_tv_size, _tv_count};

    stream_to_dataset(a, _stream_a);
    stream_to_dataset(b, _stream_b);

    for (std::size_t i = 0; i != _num_of_epochs; ++i) {
        _backend->train(a, b);

        stream_to_dataset(a, _stream_a);
        stream_to_dataset(b, _stream_b);

        pvalues.emplace_back(_backend->test(a, b));
    }

    {
        std::ofstream of("pvals.txt");
        for (auto v : pvalues)
            of << v << std::endl;
    }

    ks_uniformity_test test{pvalues, _significance_level};

    logger::info() << "KS test on p-values of size: " << pvalues.size() << std::endl;
    logger::info() << "KS statistics: " << test.test_statistic << std::endl;
    logger::info() << "KS critical value: " << _significance_level << "%: " << test.critical_value
                   << std::endl;

    if (test.test_statistic > test.critical_value) {
        logger::info() << "KS is in " << _significance_level
                       << "% interval -> uniformity hypothesis rejected" << std::endl;
    } else {
        logger::info() << "KS is not in " << _significance_level
                       << "% interval -> uniformity hypothesis accepted" << std::endl;
    }

    logger::info() << "the last p-value is: " << pvalues.back() << std::endl;
}
