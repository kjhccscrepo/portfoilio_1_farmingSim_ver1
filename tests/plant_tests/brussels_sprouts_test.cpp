#include "../../src/plants/brussels_sprouts.hpp"
#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>
#include "../../src/plant.hpp"

TEST_CASE( "it returns a x as its when it is a seedling" ) {
    Brussels_Sprouts brussel;
    REQUIRE( brussel.symbol() == "x" );
}
