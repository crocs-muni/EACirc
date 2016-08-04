#pragma once

#include "../dataset.h"
#include "../statistics.h"
#include "circuit.h"
#include "interpreter.h"
#include <core/random.h>

namespace circuit {

template <class Def> struct helper {
    template <class Generator>
    static std::uint8_t generate_argument(Generator &g) {
        std::uniform_int_distribution<std::uint8_t> dst;
        return dst(g);
    }

    template <class Generator> static function generate_function(Generator &g) {
// TODO
#error TODO
    }

    template <class Generator>
    static connectors<Def> generate_connetors(Generator &g, std::size_t size) {
// TODO
#error TODO
    }
};

template <class Generator, class Def> struct basic_mutator final : mutator {
    basic_mutator(Generator &g)
        : _g(g) {}

    void apply(backend &bck) override {
        using node_distribution = std::uniform_int_distribution<std::size_t>;

        auto circ = dynamic_cast<circuit<Def> &>(bck);
        node_distribution dst{0, circuit<Def>::num_of_nodes};

        for (std::size_t i = 0; i != _function_distance; ++i)
            circ.node(dst(g)).function = helper<Def>::generate_function(_g);
        for (std::size_t i = 0; i != _argument_distance; ++i)
            circ.node(dst(g)).argument = helper<Def>::generate_argument(_g);
        for (std::size_t i = 0; i != _connector_distance; ++i)
            mutate_connectors(circ, node_dst(_g));
    }

private:
    Generator &_g;
    std::size_t _function_distance;
    std::size_t _argument_distance;
    std::size_t _connector_distance;

    void _mutate_connectors(circuit<Def> &circ, std::size_t node) {
        if (node < Def::x) {
            // mutate connector in first layer
            std::uniform_int_distribution<std::size_t> dst{0, Def::in - 1};
            circ.node(node).connectors.flip(dst(_g));
        } else {
            // mutate connector in other layers
            std::uniform_int_distribution<std::size_t> dst{0, Def::x - 1};
            circ.node(node).connectors.flip(dst(_g));
        }
    }
};

template <class Def> struct categories_evluator final : evaluator {
    categories_evluator(std::size_t categories)
        : _chisqr(categories) {}

    double apply(const backend &bck) override {
        interpreter<Def> kernel{dynamic_cast<circuit<Def> &>(bck)};

        _out_a.clear();
        _out_b.clear();

        std::transform(_in_a.begin(), _in_a.end(),
                       std::back_inserter(_out_a.begin()), kernel);
        std::transform(_in_b.begin(), _in_b.end(),
                       std::back_inserter(_out_b.begin()), kernel);

        return 1. - _chisqr(_out_a, _out_b);
    }

private:
    dataset<Def::in> _in_a;
    dataset<Def::in> _in_b;
    dataset<Def::out> _out_a;
    dataset<Def::out> _out_b;
    two_sample_chisqr _chisqr;
};

} // namespace circuit