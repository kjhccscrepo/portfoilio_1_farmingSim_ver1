#include "../../src/plants/melon.hpp"
#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../../src/plant.hpp"
TEST_CASE( "it returns a v as its when it is a seedling" ) {
  Melon melon;
  REQUIRE( melon.symbol() == "p" );
}
TEST_CASE( "it returns a o when the carrot is half-grown" ) {
  Melon melon;
  melon.end_day();
  REQUIRE( melon.symbol() == "p" );
  melon.end_day();
  melon.end_day();
  REQUIRE( melon.symbol() == "o" );
}
TEST_CASE( "it returns a O when the carrot is fully grown" ) {
  Melon melon;
  REQUIRE( melon.symbol() == "p" );
  melon.end_day();
  melon.end_day();
  melon.end_day();
  REQUIRE( melon.symbol() == "o" );
  melon.end_day();
  melon.end_day();
  melon.end_day();
  melon.end_day();
  REQUIRE( melon.symbol() == "O" );
}