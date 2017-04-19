#include "eacirc.h"
#include "statistics.h"
#include <eacirc-core/version.h>
#include <eacirc-core/logger.h>
#include <eacirc-core/random.h>
#include <fstream>
#include <pcg/pcg_random.hpp>

#include "circuit/backend.h"
#include <eacirc-streams/stream.h>
#include <eacirc-streams/streams.h>

static std::ifstream open_config_file(std::string path) {
    std::ifstream file(path);
    if (!file.is_open())
        throw std::runtime_error("can't open config file " + path);
    return file;
}

eacirc::eacirc(cmd_options options)
    : eacirc(options, open_config_file(options.config)) {}

eacirc::eacirc(cmd_options options, json const& config)
    : _cmd_options(options)
    , _config_file(config)
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
        logger::info() << "stream a: type: " << config.at("stream-a").at("type") << std::endl;
        _stream_a = make_stream(config.at("stream-a"), main_seeder, _tv_size);
        logger::info() << "stream b: type: " << config.at("stream-b").at("type") << std::endl;
        _stream_b = make_stream(config.at("stream-b"), main_seeder, _tv_size);
    }

    {
        std::string backend_type = config.at("backend").at("type");
        if (backend_type == "circuit") {
            _backend = circuit::create_backend(_tv_size, config.at("backend"), main_seeder);
            _backend->set_produce_file("scores.txt", !_cmd_options.not_produce_scores);
        } else
            throw std::runtime_error("no backend named [" + backend_type + "] is available");
    }
}

void eacirc::run() {
    std::vector<double> pvalues;
    pvalues.reserve(_num_of_epochs);

    dataset a{_tv_size, _tv_count};
    dataset b{_tv_size, _tv_count};

    for (std::size_t i = 0; i != _num_of_epochs; ++i) {
        _backend->train(a, b);

        stream_to_dataset(a, _stream_a);
        stream_to_dataset(b, _stream_b);

        pvalues.emplace_back(_backend->test(a, b));
    }

    if (!_cmd_options.not_produce_pvals) {
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

    dataset final_a{_tv_size, _tv_count * _num_of_epochs};
    dataset final_b{_tv_size, _tv_count * _num_of_epochs};

    stream_to_dataset(final_a, _stream_a);
    stream_to_dataset(final_b, _stream_b);

    logger::info() << "The p-value of the last individual is: " << _backend->test(final_a, final_b) << std::endl;
}
