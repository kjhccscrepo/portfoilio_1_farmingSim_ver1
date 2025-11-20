#include "../../plots/soil.hpp"
#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

Soil soil;
TEST_CASE( "it returns a ~ as its symbol" ) {
    REQUIRE( soil.symbol() == "~" );
}
TEST_CASE( "end_day is a no-op" ) {
    soil.end_day();
    REQUIRE( soil.symbol() == "~" );
}
TEST_CASE( "it returns a -1 as its harvest file" ) {
    REQUIRE( soil.harvest() == -1 );
}
TEST_CASE("Soil being watered does nothing") {
    soil.water();
    REQUIRE( soil.symbol() == "~" );
}
TEST_CASE("its name is working") {
    soil.water();
    REQUIRE( soil.myName() == "soil" );
}