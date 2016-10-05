#include "streams.h"
#include "streams/files.h"
#include "streams/generators.h"
#include "streams/sha3/sha3.h"
#include <string>

std::unique_ptr<stream> make_stream(json const& config, default_seed_source& seeder) {
    std::string type = config.at("type");

    if (type == "file-stream")
        return std::make_unique<streams::file_stream>(config);
    else if (type == "true-stream")
        return std::make_unique<streams::true_stream>();
    else if (type == "false-stream")
        return std::make_unique<streams::true_stream>();
    else if (type == "mt19937-stream")
        return std::make_unique<streams::mt19937_stream>(seeder);
    else if (type == "pcg32-stream")
        return std::make_unique<streams::pcg32_stream>(seeder);
    else if (type == "sha3-stream")
        return std::make_unique<sha3::sha3_stream>(config);
    else
        throw std::runtime_error("no such stream named \"" + type + "\" is available");
}