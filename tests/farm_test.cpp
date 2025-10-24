#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/farm.hpp"

#include <iostream>

TEST_CASE("correctly constructs a 6 x 7 farm out of soil") {
    int x_test = 6;
    int y_test = 7;
    farm testFarm(x_test, y_test);
    REQUIRE( testFarm.getXUpBound() == x_test );
    REQUIRE( testFarm.getYUpBound() == y_test );
    for (int x = 0; x < x_test; x++) {
        for (int y = 0; y < y_test; y++) {
            REQUIRE( testFarm.getSymbol(x, y) == '~' );
        }
    }
}


