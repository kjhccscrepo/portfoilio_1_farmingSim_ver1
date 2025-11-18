#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>
#include "../src/farm_and_friends/farm.hpp"
#include "../src/inventory.hpp"
#include "../src/item.hpp"
#include "../src/player.hpp"
#include "../src/farm_and_friends/plant.hpp"
#include "../src/farm_and_friends/plot.hpp"
#include "../src/items/produce.hpp"
#include "../src/items/seeds.hpp"
#include "../src/plants/carrot.hpp"
#include "../src/plants/melon.hpp"
TEST_CASE( "it can be initialized with a single plot" ) {
  Player player;
  Farm farm(1, 1);
  farm.link_Player(&player);
  REQUIRE( farm.row_capacity() == 1 );
  REQUIRE( farm.column_capacity() == 1 );
}
TEST_CASE( "it can be initialized as a 1x2 farm" ) {
  Player player;
  Farm farm(1, 2);
  farm.link_Player(&player);
  REQUIRE( farm.row_capacity() == 1 );
  REQUIRE( farm.column_capacity() == 2 );
}
TEST_CASE( "it can be initialized as a 2x1 farm" ) {
  Player player;
  Farm farm(2, 1);
  farm.link_Player(&player);
  REQUIRE( farm.row_capacity() == 2 );
  REQUIRE( farm.column_capacity() == 1 );
}
TEST_CASE( "it returns the symbol for a single soil plot" ) {
  Player player;
  Farm farm(1, 1);
  farm.link_Player(&player);
  REQUIRE( farm.get_symbol(0, 0) == "P" );
}
TEST_CASE( "it returns the symbols for a 1x2 farm" ) {
  Player player;
  Farm farm(1, 2);
  farm.link_Player(&player);
  REQUIRE( farm.get_symbol(0, 0) == "P" );
  REQUIRE( farm.get_symbol(0, 1) == "." );
}
TEST_CASE( "it returns the symbols for a 2x1 farm" ) {
  Player player;
  Farm farm(2, 1);
  farm.link_Player(&player);
  REQUIRE( farm.get_symbol(0, 0) == "P" );
  REQUIRE( farm.get_symbol(1, 0) == "." );
}
TEST_CASE( "it allows us to plant a carrot" ) {
  Player player;
  Farm farm(1, 2);
  farm.link_Player(&player);
  Carrot carrot;
  farm.plant(0, 1, &carrot);
  REQUIRE( farm.get_symbol(0, 1) == "v" );
}
TEST_CASE( "we can grow, then harvest a melon, and add it to our inventory" ) {
  Player player;
  inventory inventory_test;
  Melon melon;
  seeds seed_melon(&melon);
  produce produce_melon(&melon);
  melon.link_this_class(&seed_melon, &produce_melon, &inventory_test);
  Farm farm(3, 3);
  farm.link_Player(&player);
  player.set_bounds(3, 3);
  farm.plant(2, 2, &melon);
  REQUIRE( farm.get_symbol(2, 2) == "p" );
  farm.end_day();
  REQUIRE( farm.get_symbol(2, 2) == "p" );
  farm.end_day();
  REQUIRE( farm.get_symbol(2, 2) == "p" );
  farm.end_day();
  REQUIRE( farm.get_symbol(2, 2) == "o" );
  farm.end_day();
  REQUIRE( farm.get_symbol(2, 2) == "o" );
  farm.end_day();
  REQUIRE( farm.get_symbol(2, 2) == "o" );
  farm.end_day();
  REQUIRE( farm.get_symbol(2, 2) == "o" );
  farm.end_day();
  REQUIRE( farm.get_symbol(2, 2) == "O" );
  farm.end_day();
  REQUIRE( farm.get_symbol(2, 2) == "O" );
  //still a melon after another tick^
  REQUIRE( farm.get_symbol(0, 0) == "P" );
  player.move_down();
  player.move_right();
  REQUIRE( farm.get_symbol(1, 1) == "P" );
  player.move_down();
  player.move_right();
  REQUIRE( farm.get_symbol(2, 2) == "P" );
  //player is now on the melon
  // a return value of less than 0 means the item is NOT in the inventory of the player yet.
  REQUIRE( inventory_test.has(&produce_melon) < 0);
  REQUIRE( inventory_test.has(&seed_melon) < 0);
  // if a return value is 0 or more it has an index in the vector, anything negative would mean not present!
  if (farm.harvest_val() == 3) { // 3 means it can and will be harvested
    farm.set_soil();
  }
  player.move_left();
  REQUIRE( farm.get_symbol(2, 2) == "." );
  // it is now soil
  REQUIRE( inventory_test.has(&produce_melon) >= 0);
  REQUIRE( inventory_test.has(&seed_melon) >= 0);
  // if a return value is 0 or more it has an index in the vector, anything negative would mean not present!
}