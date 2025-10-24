#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>
#include "../src/farm_brain.hpp"
#include "../src/farm.hpp"
#include "../src/player.hpp"


TEST_CASE( "farm construction" ) {
    farm testFarm(8, 5);
    std::vector<items> inventory;
    player joe(&inventory, "P", "joe");
    farm_brain testBrain(&testFarm, &joe);
    testBrain.generate_printer();
    std::stringstream expected_result;
    expected_result     << "//////////\n"
                        << "/~~~~~~~~/\n"
                        << "/~~~~~~~~/\n"
                        << "/~~~~~~~~/\n"
                        << "/~~~~~~~~/\n"
                        << "/P~~~~~~~/\n"
                        << "//////////\n";
    REQUIRE( testBrain.printFarm() == expected_result.str() );
}
