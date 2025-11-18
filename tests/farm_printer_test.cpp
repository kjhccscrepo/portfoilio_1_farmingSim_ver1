#include "../src/farm_printer.hpp"
#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>
#include "../src/farm.cpp"
#include "../src/inventory.hpp"
#include "../src/item.hpp"
#include "../src/plant.cpp"
#include "../src/player.hpp"
#include "../src/plot.hpp"
#include "../src/soil.cpp"
#include "../src/weed.hpp"
#include "../src/items/produce.hpp"
#include "../src/items/seeds.hpp"
#include "../src/plants/carrot.hpp"
#include "../src/plants/melon.hpp"

TEST_CASE( "it pretty prints a single plot of land" ) {
    Player p;
    Farm farm(1, 1);
    farm.link_Player(&p);
    FarmPrinter printer(&farm);
    std::stringstream expected;
  expected  << "/ / / \n"
            << "/ P / \n"
            << "/ / / \n";
  REQUIRE( printer.prettyPrint().str() == expected.str() );
}

TEST_CASE( "it pretty prints a 1x2 farm" ) {
  Player player;
  Farm farm(1, 2);
    farm.link_Player(&player);
  FarmPrinter printer(&farm);
  std::stringstream expected;
  expected  << "/ / / \n"
            << "/ P / \n"
            << "/ . / \n"
            << "/ / / \n";
  REQUIRE( printer.prettyPrint().str() == expected.str() );
}
TEST_CASE( "it pretty prints a 2x1 farm" ) {
  Player player;
  Farm farm(2, 1);
    farm.link_Player(&player);
  FarmPrinter printer(&farm);
  std::stringstream expected;
  expected  << "/ / / / \n"
            << "/ P . / \n"
            << "/ / / / \n";
  REQUIRE( printer.prettyPrint().str() == expected.str() );
}
TEST_CASE( "it pretty prints a 2x2 farm" ) {
    Player player;
    Farm farm(2, 2);
    farm.link_Player(&player);
    FarmPrinter printer(&farm);
    std::stringstream expected;
    expected  << "/ / / / \n"
              << "/ P . / \n"
              << "/ . . / \n"
              << "/ / / / \n";
    REQUIRE( printer.prettyPrint().str() == expected.str() );
}
TEST_CASE( "player moves" ) {
    Player player;
    Farm farm(3, 3);
    farm.link_Player(&player);
    player.set_bounds(3, 3);
    FarmPrinter printer(&farm);
    std::stringstream expected;
    expected  << "/ / / / / \n"
              << "/ P . . / \n"
              << "/ . . . / \n"
              << "/ . . . / \n"
              << "/ / / / / \n";
    REQUIRE( printer.prettyPrint().str() == expected.str() );
    player.move_right();
    expected.str("");
    expected.clear();
    expected    << "/ / / / / \n"
                << "/ . P . / \n"
                << "/ . . . / \n"
                << "/ . . . / \n"
                << "/ / / / / \n";
    REQUIRE( printer.prettyPrint().str() == expected.str() );
    player.move_left();
    player.move_down();
    player.move_down();
    expected.str("");
    expected.clear();
    expected    << "/ / / / / \n"
                << "/ . . . / \n"
                << "/ . . . / \n"
                << "/ P . . / \n"
                << "/ / / / / \n";
    REQUIRE( printer.prettyPrint().str() == expected.str() );
    player.move_right();
    player.move_up();
    expected.str("");
    expected.clear();
    expected    << "/ / / / / \n"
                << "/ . . . / \n"
                << "/ . P . / \n"
                << "/ . . . / \n"
                << "/ / / / / \n";
    REQUIRE( printer.prettyPrint().str() == expected.str() );
    player.move_left();
    player.move_up();
    expected.str("");
    expected.clear();
    expected    << "/ / / / / \n"
                << "/ P . . / \n"
                << "/ . . . / \n"
                << "/ . . . / \n"
                << "/ / / / / \n";
    REQUIRE( printer.prettyPrint().str() == expected.str() );
    player.move_right();
    player.move_right();
    player.move_down();
    player.move_down();
    expected.str("");
    expected.clear();
    expected    << "/ / / / / \n"
                << "/ . . . / \n"
                << "/ . . . / \n"
                << "/ . . P / \n"
                << "/ / / / / \n";
    REQUIRE( printer.prettyPrint().str() == expected.str() );
}
TEST_CASE( "player plants a carrot" ) {
    Player player;
    inventory inventory;
    Farm farm(3, 3);
    farm.link_Player(&player);
    player.set_bounds(3, 3);
    FarmPrinter printer(&farm);
    Carrot carrot;
    seeds seed_carrot(&carrot);
    produce produce_carrot(&carrot);
    carrot.link_this_class(&seed_carrot, &produce_carrot, &inventory);
    inventory.add_item(&seed_carrot);
    std::stringstream expected;
    expected  << "/ / / / / \n"
              << "/ P . . / \n"
              << "/ . . . / \n"
              << "/ . . . / \n"
              << "/ / / / / \n";
    REQUIRE( printer.prettyPrint().str() == expected.str() );
    farm.plant(player.getX(), player.getY(), &carrot);
    player.move_right();
    player.move_down();
    expected.str("");
    expected.clear();
    expected    << "/ / / / / \n"
                << "/ v . . / \n"
                << "/ . P . / \n"
                << "/ . . . / \n"
                << "/ / / / / \n";
    REQUIRE( printer.prettyPrint().str() == expected.str() );
}
TEST_CASE( "player grows a carrot" ) {
    Player player;
    inventory inventory;
    Farm farm(3, 3);
    farm.link_Player(&player);
    player.set_bounds(3, 3);
    FarmPrinter printer(&farm);
    Carrot carrot;
    seeds seed_carrot(&carrot);
    produce produce_carrot(&carrot);
    carrot.link_this_class(&seed_carrot, &produce_carrot, &inventory);
    inventory.add_item(&seed_carrot);
    farm.plant(player.getX(), player.getY(), &carrot);
    player.move_right();
    player.move_down();
    std::stringstream expected;
    expected.str("");
    expected.clear();
    expected    << "/ / / / / \n"
                << "/ v . . / \n"
                << "/ . P . / \n"
                << "/ . . . / \n"
                << "/ / / / / \n";
    REQUIRE( printer.prettyPrint().str() == expected.str() );
    farm.end_day();
    expected.str("");
    expected.clear();
    expected    << "/ / / / / \n"
                << "/ V . . / \n"
                << "/ . P . / \n"
                << "/ . . . / \n"
                << "/ / / / / \n";
    REQUIRE( printer.prettyPrint().str() == expected.str() );
    farm.end_day();
    expected.str("");
    expected.clear();
    expected    << "/ / / / / \n"
                << "/ W . . / \n"
                << "/ . P . / \n"
                << "/ . . . / \n"
                << "/ / / / / \n";
    REQUIRE( printer.prettyPrint().str() == expected.str() );
}
TEST_CASE( "player harvests a melon" ) {
    Player player;
    inventory inventory;
    Farm farm(3, 3);
    farm.link_Player(&player);
    player.set_bounds(3, 3);
    FarmPrinter printer(&farm);
    Melon melon;
    seeds seed_melon(&melon);
    produce produce_melon(&melon);
    melon.link_this_class(&seed_melon, &produce_melon, &inventory);
    inventory.add_item(&seed_melon);
    farm.plant(player.getX(), player.getY(), &melon);
    player.move_right();
    player.move_down();
    std::stringstream expected;
    expected.str("");
    expected.clear();
    expected    << "/ / / / / \n"
                << "/ p . . / \n"
                << "/ . P . / \n"
                << "/ . . . / \n"
                << "/ / / / / \n";
    REQUIRE( printer.prettyPrint().str() == expected.str() );
    farm.end_day();
    expected.str("");
    expected.clear();
    expected    << "/ / / / / \n"
                << "/ p . . / \n"
                << "/ . P . / \n"
                << "/ . . . / \n"
                << "/ / / / / \n";
    REQUIRE( printer.prettyPrint().str() == expected.str() );
    farm.end_day();
    expected.str("");
    expected.clear();
    expected    << "/ / / / / \n"
                << "/ p . . / \n"
                << "/ . P . / \n"
                << "/ . . . / \n"
                << "/ / / / / \n";
    REQUIRE( printer.prettyPrint().str() == expected.str() );
    farm.end_day();
    expected.str("");
    expected.clear();
    expected    << "/ / / / / \n"
                << "/ o . . / \n"
                << "/ . P . / \n"
                << "/ . . . / \n"
                << "/ / / / / \n";
    REQUIRE( printer.prettyPrint().str() == expected.str() );
    farm.end_day();
    expected.str("");
    expected.clear();
    expected    << "/ / / / / \n"
                << "/ o . . / \n"
                << "/ . P . / \n"
                << "/ . . . / \n"
                << "/ / / / / \n";
    REQUIRE( printer.prettyPrint().str() == expected.str() );
    farm.end_day();
    expected.str("");
    expected.clear();
    expected    << "/ / / / / \n"
                << "/ o . . / \n"
                << "/ . P . / \n"
                << "/ . . . / \n"
                << "/ / / / / \n";
    REQUIRE( printer.prettyPrint().str() == expected.str() );
    farm.end_day();
    expected.str("");
    expected.clear();
    expected    << "/ / / / / \n"
                << "/ o . . / \n"
                << "/ . P . / \n"
                << "/ . . . / \n"
                << "/ / / / / \n";
    REQUIRE( printer.prettyPrint().str() == expected.str() );
    farm.end_day();
    expected.str("");
    expected.clear();
    expected    << "/ / / / / \n"
                << "/ O . . / \n"
                << "/ . P . / \n"
                << "/ . . . / \n"
                << "/ / / / / \n";
    REQUIRE( printer.prettyPrint().str() == expected.str() );
    player.move_left();
    player.move_up();
    if (farm.harvest_val() == 3) {
        farm.set_soil();
    }
    player.move_right();
    expected.str("");
    expected.clear();
    expected    << "/ / / / / \n"
                << "/ . P . / \n"
                << "/ . . . / \n"
                << "/ . . . / \n"
                << "/ / / / / \n";

}