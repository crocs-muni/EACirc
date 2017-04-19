#pragma once

#include "backend.h"
#include "circuit.h"
#include "genetics.h"
#include <eacirc-core/memory.h>
#include <fstream>
#include <solvers/local_search.h>

namespace circuit {

    template <typename Circuit> struct global_search : backend {
        template <typename Sseq>
        global_search(unsigned tv_size, json const& config, Sseq&& seed)
            : _function_set(config.at("function-set"))
            , _num_of_generations(config.at("num-of-generations"))
            , _solver(Circuit(tv_size),
                      ini(config.at("initializer"), _function_set),
                      mut(config.at("mutator"), _function_set),
                      eva(config.at("evaluator")),
                      std::forward<Sseq>(seed)) {}

        ~global_search() {
            if (_produce_scores_file) {
                std::ofstream out("scores.txt");
                for (double score : _solver.scores())
                    out << score << std::endl;
            }
        }

        void train(dataset const& a, dataset const& b) override {
            _solver.reevaluate(a, b);
            _solver.run(_num_of_generations);
        }

        double test(dataset const& a, dataset const& b) override {
            return _solver.reevaluate(a, b);
        }

        virtual void set_produce_file(std::string filename, bool value) override {
            if (filename == "scores.txt") {
                _produce_scores_file = value;
            } else
                throw std::runtime_error("File '" + filename + "' is not produce with this backend");
        }

    private:
        using ini = basic_initializer;
        using mut = basic_mutator;
        using eva = categories_evaluator<Circuit>;

        fn_set _function_set;
        std::uint64_t _num_of_generations;
        solvers::local_search<Circuit, ini, mut, eva> _solver;
        bool _produce_scores_file = true;
    };

    std::unique_ptr<backend>
    create_backend(unsigned tv_size, json const& config, default_seed_source& seed) {
        std::string solver = config.at("solver");

        if (solver == "global-search")
            return std::make_unique<global_search<circuit<8, 5, 1>>>(tv_size, config, seed);
        else
            throw std::runtime_error("no such solver named [" + solver + "] is avalable");
    }

} // namespace circuit
