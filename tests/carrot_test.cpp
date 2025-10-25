#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>
#include "../src/plants/carrot.hpp"
#include "../src/plant.hpp"

TEST_CASE( "it returns a v as its when it is a seedling" ) {
  Carrot carrot;
  REQUIRE( carrot.symbol() == "v" );
}

TEST_CASE( "it returns a V when the carrot is half-grown" ) {
  Carrot carrot;
  carrot.end_day();
  REQUIRE( carrot.symbol() == "V" );
}

TEST_CASE( "it returns a W when the carrot is fully grown" ) {
  Carrot carrot;
  carrot.end_day();
  carrot.end_day();
  REQUIRE( carrot.symbol() == "W" );
}
