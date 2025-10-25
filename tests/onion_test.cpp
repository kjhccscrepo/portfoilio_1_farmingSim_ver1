#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>
#include "../src/plants/onion.hpp"
#include "../src/plants.hpp"
#include "../src/plot.hpp"
#include "../src/inventory.hpp"

TEST_CASE( "it returns a y as its when it is a seedling" ) {
    Onion onion;
    REQUIRE( onion.symbol() == "y" );
}
TEST_CASE( "it returns a y for 4 days, then matures" ) {
    Onion onion;
    REQUIRE( onion.symbol() == "y" );
    onion.end_day();
    REQUIRE( onion.symbol() == "y" );
    onion.end_day();
    REQUIRE( onion.symbol() == "y" );
    onion.end_day();
    REQUIRE( onion.symbol() == "y" );
    onion.end_day();
    REQUIRE( onion.symbol() == "Y" );
}
TEST_CASE( "it returns a Y when it is is grown" ) {
    Onion onion;
    for (int i = 0; i < 5; i++) {
        onion.end_day();
    }
    REQUIRE( onion.symbol() == "Y" );
}