#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/plants/melon.hpp"
#include "../src/plants.hpp"
#include "../src/plot.hpp"
#include "../src/inventory.hpp"

TEST_CASE( "it returns a v as its when it is a seedling" ) {
  Melon melon;
  REQUIRE( melon.symbol() == "v" );
}

TEST_CASE( "it returns a V when the carrot is half-grown" ) {
  Melon melon;
  melon.end_day();
  REQUIRE( melon.symbol() == "V" );
}

TEST_CASE( "it returns a W when the carrot is fully grown" ) {
  Melon melon;
  melon.end_day();
  melon.end_day();
  REQUIRE( melon.symbol() == "W" );
}
