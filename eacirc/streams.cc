#include "streams.h"
#include <algorithm>
#include <core/json.h>
#include <core/memory.h>
#include <core/stream.h>
#include <fstream>
#include <limits>
#include <pcg/pcg_random.hpp>
#include <random>
#include <string>

#ifdef BUILD_estream
#include <streams/estream/estream_stream.h>
#endif

#ifdef BUILD_sha3
#include <streams/sha3/sha3_stream.h>
#endif

namespace _impl {

    template <std::uint8_t value> struct const_stream : stream {
        const_stream(const std::size_t osize)
            : stream(osize)
            , _data(osize) {
            std::fill_n(_data.begin(), osize, value);
        }

        vec_view next() override { return make_cview(_data); }

    private:
        std::vector<value_type> _data;
    };

    template <typename Generator> struct rng_stream : stream {
        template <typename Seeder>
        rng_stream(Seeder&& seeder, const std::size_t osize)
            : stream(osize)
            , _rng(std::forward<Seeder>(seeder))
            , _data(osize) { }

        vec_view next() override {
            std::generate_n(_data.data(), osize(), [this]() {
                return std::uniform_int_distribution<std::uint8_t>()(_rng);
            });
            return make_cview(_data);
        }

    private:
        Generator _rng;
        std::vector<value_type> _data;
    };

} // namespace _impl

/**
 * \brief Stream of true bits
 */
using true_stream = _impl::const_stream<std::numeric_limits<std::uint8_t>::max()>;

/**
 * \brief Stream of false bits
 */
using false_stream = _impl::const_stream<std::numeric_limits<std::uint8_t>::min()>;

/**
 * \brief Stream of data produced by Merseine Twister
 */
using mt19937_stream = _impl::rng_stream<std::mt19937>;

/**
 * \brief Stream of data produced by PCG (Permutation Congruential Generator)
 */
using pcg32_stream = _impl::rng_stream<pcg32>;

/**
 * @brief Stream of data read from a file
 */
struct file_stream : stream {
    file_stream(const json& config, const std::size_t osize)
        : stream(osize)
        , _path(config.at("path").get<std::string>())
        , _istream(_path, std::ios::binary)
        , _data(osize) {}

    vec_view next() override {
        _istream.read(_data.data(), osize());

        if (_istream.fail())
            throw std::runtime_error("I/O error while reading a file " + _path);
        if (_istream.eof())
            throw std::runtime_error("end of file " + _path + " reached, not enough data!");

        return make_cview(_data);
    }

private:
    const std::string _path;
    std::basic_ifstream<std::uint8_t> _istream;
    std::vector<value_type> _data;
};

/**
 * @brief Stream of counter
 */
struct counter : stream {
    counter(const std::size_t osize)
        : stream(osize)
        , _data(osize) {
        std::fill(_data.begin(), _data.end(), std::numeric_limits<value_type>::min());
    }

    vec_view next() override {
        for (value_type& value : _data) {
            if (value != std::numeric_limits<value_type>::max()) {
                ++value;
                break;
            }
            value = std::numeric_limits<value_type>::min();
        }
        return make_cview(_data);
    }

private:
    std::vector<value_type> _data;
};

std::unique_ptr<stream>
make_stream(const json& config, default_seed_source& seeder, std::size_t osize = 0) {
    const std::string type = config.at("type");

    // probably unnecessary
    if (osize == 0)
        osize = config.at("size");

    if (type == "mt19937-stream")
        return std::make_unique<mt19937_stream>(seeder, osize);
    else if (type == "pcg32-stream")
        return std::make_unique<pcg32_stream>(seeder, osize);
#ifdef BUILD_estream
    else if (type == "estream")
        return std::make_unique<estream_stream>(config, seeder, osize);
#endif
#ifdef BUILD_sha3
    else if (type == "sha3")
        return std::make_unique<sha3_stream>(config, osize);
#endif
    throw std::runtime_error("requested stream named \"" + type + "\" does not exist");
}

std::unique_ptr<stream> make_stream(const json& config, std::size_t osize = 0) {
    std::string type = config.at("type");

    if (osize == 0)
        osize = config.at("size");

    if (type == "file-stream")
        return std::make_unique<file_stream>(config, osize);
    else if (type == "true-stream")
        return std::make_unique<true_stream>(osize);
    else if (type == "false-stream")
        return std::make_unique<false_stream>(osize);
    else if (type == "counter")
        return std::make_unique<counter>(osize);
#ifdef BUILD_sha3
    else if (type == "sha3")
        return std::make_unique<sha3_stream>(config, osize);
#endif
    throw std::runtime_error("requested stream named \"" + type + "\" does not exist");
}

void stream_to_dataset(dataset& set, std::unique_ptr<stream>& source) {

    auto beg = set.rawdata();
    auto end = set.rawdata() + set.rawsize();

    for (; beg != end;) {
        vec_view n = source->next();
        beg = std::copy(n.begin(), n.end(), beg);
    }
}
