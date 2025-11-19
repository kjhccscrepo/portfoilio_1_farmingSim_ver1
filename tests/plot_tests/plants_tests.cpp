
#include "../../plots/plant.hpp"
#include "../../plots/plants/beet.hpp"
#include "../../plots/plants/brussel_sprouts.hpp"
#include "../../plots/plants/carrot.hpp"
#include "../../plots/plants/lettuce.hpp"
#include "../../plots/plants/melon.hpp"
#include "../../plots/plants/onion.hpp"
#include "../../plots/plants/spinach.hpp"
#include "../../plots/plants/zucchini.hpp"
#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>
Beet beet;
Brussels_Sprouts brussel;
Carrot carrot_waterTest;
Carrot carrot;
Lettuce lettuce;
Melon melon;
Onion onion;
Spinach spinach;
Zucchini zucchini;

TEST_CASE( "A Beet behaves as expected" ) {
    REQUIRE( beet.symbol() == "x" );
    beet.end_day();
    REQUIRE( beet.symbol() == "x" );
    beet.end_day();
    REQUIRE( beet.symbol() == "b" );
    beet.end_day();
    REQUIRE( beet.symbol() == "b" );
    beet.end_day();
    REQUIRE( beet.symbol() == "b" );
    beet.end_day();
    REQUIRE( beet.symbol() == "b" );
    beet.end_day();
    REQUIRE( beet.symbol() == "b" );
    beet.end_day();
    REQUIRE( beet.symbol() == "B" );
}
TEST_CASE( "A Brussel Sprout behaves as expected" ) {
    REQUIRE( brussel.symbol() == "x" );
    brussel.end_day();
    REQUIRE( brussel.symbol() == "x" );
    brussel.end_day();
    REQUIRE( brussel.symbol() == "x" );
    brussel.end_day();
    REQUIRE( brussel.symbol() == "x" );
    brussel.end_day();
    REQUIRE( brussel.symbol() == "x" );
    brussel.end_day();
    REQUIRE( brussel.symbol() == "e" );
    brussel.end_day();
    REQUIRE( brussel.symbol() == "e" );
    brussel.end_day();
    REQUIRE( brussel.symbol() == "e" );
    brussel.end_day();
    REQUIRE( brussel.symbol() == "e" );
    brussel.end_day();
    REQUIRE( brussel.symbol() == "e" );
    brussel.end_day();
    REQUIRE( brussel.symbol() == "e" );
    brussel.end_day();
    REQUIRE( brussel.symbol() == "e" );
    brussel.end_day();
    REQUIRE( brussel.symbol() == "e" );
    brussel.end_day();
    REQUIRE( brussel.symbol() == "e" );
    brussel.end_day();
    REQUIRE( brussel.symbol() == "e" );
    brussel.end_day();
    REQUIRE( brussel.symbol() == "E" );
}
TEST_CASE( "A Carrot behaves as expected" ) {
    REQUIRE( carrot.symbol() == "x" );
    carrot.end_day();
    REQUIRE( carrot.symbol() == "w" );
    carrot.end_day();
    REQUIRE( carrot.symbol() == "W" );
}

TEST_CASE( "A Carrot being watered behaves as expected" ) {
    REQUIRE( carrot_waterTest.symbol() == "x" );
    carrot_waterTest.water();
    REQUIRE( carrot_waterTest.symbol() == "x" );
    carrot_waterTest.water();
    REQUIRE( carrot_waterTest.symbol() == "x" );
    carrot_waterTest.water();
    carrot_waterTest.water();
    carrot_waterTest.water();
    carrot_waterTest.water();
    carrot_waterTest.water();
    REQUIRE( carrot_waterTest.symbol() == "x" );
    carrot_waterTest.end_day();
    REQUIRE( carrot_waterTest.symbol() == "W" );
}

TEST_CASE( "A Lettuce behaves as expected" ) {
    REQUIRE( lettuce.symbol() == "x" );
    lettuce.end_day();
    REQUIRE( lettuce.symbol() == "x" );
    lettuce.end_day();
    REQUIRE( lettuce.symbol() == "l" );
    lettuce.end_day();
    REQUIRE( lettuce.symbol() == "l" );
    lettuce.end_day();
    REQUIRE( lettuce.symbol() == "L" );
}

TEST_CASE( "A Melon behaves as expected" ) {
    REQUIRE( melon.symbol() == "x" );
    melon.end_day();
    REQUIRE( melon.symbol() == "." );
    melon.end_day();
    REQUIRE( melon.symbol() == "." );
    melon.end_day();
    REQUIRE( melon.symbol() == "." );
    melon.end_day();
    REQUIRE( melon.symbol() == "o" );
    melon.end_day();
    REQUIRE( melon.symbol() == "o" );
    melon.end_day();
    REQUIRE( melon.symbol() == "o" );
    melon.end_day();
    REQUIRE( melon.symbol() == "O" );
}

TEST_CASE( "An Onion behaves like expected" ) {
    REQUIRE( onion.symbol() == "x" );
    onion.end_day();
    REQUIRE( onion.symbol() == "y" );
    onion.end_day();
    REQUIRE( onion.symbol() == "y" );
    onion.end_day();
    REQUIRE( onion.symbol() == "y" );
    onion.end_day();
    REQUIRE( onion.symbol() == "Y" );
}

TEST_CASE( "A Spinach behaves like expected" ) {
    REQUIRE( spinach.symbol() == "x" );
    spinach.end_day();
    REQUIRE( spinach.symbol() == "x" );
    spinach.end_day();
    REQUIRE( spinach.symbol() == "s" );
    spinach.end_day();
    REQUIRE( spinach.symbol() == "s" );
    spinach.end_day();
    REQUIRE( spinach.symbol() == "s" );
    spinach.end_day();
    REQUIRE( spinach.symbol() == "S" );
}

TEST_CASE( "A Zucchini behaves like expected" ) {
    REQUIRE( zucchini.symbol() == "x" );
    zucchini.end_day();
    REQUIRE( zucchini.symbol() == "Z" );
}

TEST_CASE( "Unexpected behaviour does not arise from interacting with matured plants" ) {
    carrot.water();
    beet.water();
    brussel.water();
    lettuce.water();
    melon.water();
    onion.water();
    spinach.water();
    zucchini.water();
    REQUIRE( zucchini.symbol() == "Z" );
    REQUIRE( spinach.symbol() == "S" );
    REQUIRE( onion.symbol() == "Y" );
    REQUIRE( melon.symbol() == "O" );
    REQUIRE( lettuce.symbol() == "L" );
    REQUIRE( carrot_waterTest.symbol() == "W" );
    REQUIRE( brussel.symbol() == "E" );
    REQUIRE( beet.symbol() == "B" );
    carrot.end_day();
    beet.end_day();
    brussel.end_day();
    lettuce.end_day();
    melon.end_day();
    onion.end_day();
    spinach.end_day();
    zucchini.end_day();
    REQUIRE( zucchini.symbol() == "Z" );
    REQUIRE( spinach.symbol() == "S" );
    REQUIRE( onion.symbol() == "Y" );
    REQUIRE( melon.symbol() == "O" );
    REQUIRE( lettuce.symbol() == "L" );
    REQUIRE( carrot_waterTest.symbol() == "W" );
    REQUIRE( brussel.symbol() == "E" );
    REQUIRE( beet.symbol() == "B" );
}