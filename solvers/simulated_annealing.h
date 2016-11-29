#pragma once

#include "individual.h"
#include <core/dataset.h>
#include <core/random.h>
#include <core/view.h>

namespace solvers {

    template <typename Genotype,
              typename Initializer,
              typename Mutator,
              typename Evaluator,
              typename Generator = default_random_generator>
    struct simulated_annealing {
        template <typename Sseq>
        simulated_annealing(Genotype&& gen, Initializer&& ini, Mutator&& mut, Evaluator&& eva, Sseq&& seed)
            : _solution(std::move(gen))
            , _neighbour(_solution)
            , _initializer(std::move(ini))
            , _mutator(std::move(mut))
            , _evaluator(std::move(eva))
            , _generator(std::forward<Sseq>(seed)) {
            _initializer.apply(_solution.genotype, _generator);
        }

        double run(std::uint64_t generations) {
            for (std::uint64_t i = 0; i != generations; ++i)
                _step();
            return _solution.score;
        }

        double reevaluate(dataset const& a, dataset const& b) {
            _evaluator.change_datasets(a, b);
            _solution.score = _evaluator.apply(_solution.genotype);
            _scores.emplace_back(_solution.score);
            return _solution.score;
        }

        auto scores() const -> view<std::vector<double>::const_iterator> {
            return make_view(_scores);
        }

    private:
        individual<Genotype, double> _solution;
        individual<Genotype, double> _neighbour;

        Initializer _initializer;
        Mutator _mutator;
        Evaluator _evaluator;
        Generator _generator;

        std::vector<double> _scores;

        void _step() {
            _neighbour = _solution;
            _mutator.apply(_neighbour.genotype, _generator);

            _neighbour.score = _evaluator.apply(_neighbour.genotype);
            if (_solution <= _neighbour) {
                _solution = std::move(_neighbour);
            } else {
                std::uniform_real_distribution<float> rnd_float(0, 1);
                float f = rnd_float(_generator);
            }
            _scores.emplace_back(_solution.score);
        }
    };

} // namespace solvers