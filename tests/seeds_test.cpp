#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>
#include "../src/items/seeds.hpp"
#include "../src/plants/zucchini.hpp"
TEST_CASE( "a seed can be made and starts with 0 quantity" ) {
    Zucchini zucchini;
    seeds seeds_zucchini(&zucchini);
    REQUIRE( seeds_zucchini.isSeed());
    REQUIRE( seeds_zucchini.quantity() == 0);
}
TEST_CASE( "a seed has the write name" ) {
    Zucchini zucchini;
    seeds seeds_zucchini(&zucchini);
    REQUIRE( seeds_zucchini.getMyName() == "Zucchini seeds");
}
TEST_CASE( "it's quantity can be modified" ) {
    Zucchini zucchini;
    seeds seeds_zucchini(&zucchini);
    seeds_zucchini.increase_quantity();
    seeds_zucchini.increase_quantity();
    REQUIRE( seeds_zucchini.quantity() == 2);
    seeds_zucchini.decrease_quantity();
    REQUIRE( seeds_zucchini.quantity() == 1);
    seeds_zucchini.decrease_quantity();
    REQUIRE( seeds_zucchini.quantity() == 0);
}
TEST_CASE( "it returns a pointer to its plant" ) {
    Zucchini zucchini;
    Zucchini *z_ptr;
    z_ptr = &zucchini;
    seeds seeds_zucchini(&zucchini);
    REQUIRE( seeds_zucchini.pointer() == z_ptr);
}