#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>
#include "../../src/plants/carrot.hpp"
#include "../../src/farm_and_friends/plant.hpp"

TEST_CASE( "it returns a x as its when it is a seedling" ) {
  Carrot carrot;
  REQUIRE( carrot.symbol() == "x" );
}

TEST_CASE( "it returns a V when the carrot is half-grown" ) {
  Carrot carrot;
  carrot.end_day();
  REQUIRE( carrot.symbol() == "w" );
}

TEST_CASE( "it returns a W when the carrot is fully grown" ) {
  Carrot carrot;
  carrot.end_day();
  carrot.end_day();
  REQUIRE( carrot.symbol() == "W" );
}

TEST_CASE( "carrot can be watered to grow fully" ) {
  Carrot carrot;
  REQUIRE( carrot.symbol() == "x" );
  carrot.water();
  REQUIRE( carrot.symbol() == "x" );
  carrot.end_day();
  REQUIRE( carrot.symbol() == "W" );
}
TEST_CASE( "watering the carrot doesn't do anything" ) {
  Carrot carrot;
  REQUIRE( carrot.symbol() == "x" );
  carrot.water();
  REQUIRE( carrot.symbol() == "x" );
  carrot.water();
  REQUIRE( carrot.symbol() == "x" );
  carrot.water();
  carrot.water();
  carrot.water();
  carrot.water();
  carrot.water();
  REQUIRE( carrot.symbol() == "x" );
  carrot.end_day();
  REQUIRE( carrot.symbol() == "W" );
}