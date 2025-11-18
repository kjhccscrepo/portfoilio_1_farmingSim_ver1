#include "../src/items/produce.hpp"

#include "../src/plants/zucchini.hpp"


#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>


TEST_CASE("a seed can be made and starts with 0 quantity") {
    Zucchini zucchini;
    produce produce_zucchini(&zucchini);
    REQUIRE(produce_zucchini.isSeed() == false);
    REQUIRE(produce_zucchini.quantity() == 0);
}

TEST_CASE("a produce has the write name") {
    Zucchini zucchini;
    produce produce_zucchini(&zucchini);
    REQUIRE(produce_zucchini.getMyName() == "Zucchini(s)");
}

TEST_CASE("it's quantity can be modified") {
    Zucchini zucchini;
    produce produce_zucchini(&zucchini);
    produce_zucchini.increase_quantity();
    produce_zucchini.increase_quantity();
    REQUIRE(produce_zucchini.quantity() == 2);
    produce_zucchini.decrease_quantity();
    REQUIRE(produce_zucchini.quantity() == 1);
    produce_zucchini.decrease_quantity();
    REQUIRE(produce_zucchini.quantity() == 0);
}

TEST_CASE("it returns a pointer to its plant") {
    Zucchini zucchini;
    Zucchini *z_ptr = &zucchini;
    produce produce_zucchini(&zucchini);
    REQUIRE(produce_zucchini.pointer() == z_ptr);
}
