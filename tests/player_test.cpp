#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>
#include "../src/player.hpp"

TEST_CASE( "it starts the player in row zero, column zero" ) {
  Player test_player;
  REQUIRE( test_player.row() == 0 );
  REQUIRE( test_player.column() == 0 );
}
TEST_CASE( "it moves the player to the right" ) {
  Player test_player;
  test_player.move_right();
  REQUIRE( test_player.row() == 0 );
  REQUIRE( test_player.column() == 1 );
}
TEST_CASE( "it moves the player down" ) {
  Player test_player;
  test_player.move_down();
  REQUIRE( test_player.row() == 1 );
  REQUIRE( test_player.column() == 0 );
}
