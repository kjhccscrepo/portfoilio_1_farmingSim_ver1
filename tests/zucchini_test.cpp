#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>
#include "../src/plants/zucchini.hpp"
#include "../src/plant.hpp"
#include "../src/plot.hpp"
#include "../src/inventory.hpp"

TEST_CASE( "it returns a z as its when it is a seedling" ) {
  Zucchini zucchini;
  REQUIRE( zucchini.symbol() == "z" );
}

TEST_CASE( "it returns a Z when the Zucchini is fully-grown" ) {
  Zucchini zucchini;
  zucchini.end_day();
  REQUIRE( zucchini.symbol() == "Z" );
}

