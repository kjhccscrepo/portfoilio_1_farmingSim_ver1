#include "../src/game_printer.hpp"

#include "../src/player.hpp"
#include "../src/inventory.hpp"
#include "../src/farm.hpp"
#include "../src/item.hpp"
#include "../src/items/seeds.hpp"
#include "../src/items/produce.hpp"
#include "../src/plants/carrot.hpp"
#include "../src/plants/melon.hpp"
#include "../src/plant.hpp"
#include "../src/farm_printer.hpp"

#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

TEST_CASE( "game printer constructs an expected base output" ) {
    inventory inventory_test;
    Carrot carrot;
    produce carrot_produce(&carrot);
    seeds carrot_seeds(&carrot);
    carrot.link_this_class(&carrot_seeds, &carrot_produce, &inventory_test);
    inventory_test.add_item(&carrot_seeds);
    Player p;
    p.set_bounds(5, 5);
    p.better_start_position();
    Farm farm(5, 5);
    farm.link_Player(&p);
    FarmPrinter printer_farm(&farm);
    GamePrinter printer(&printer_farm, &inventory_test);
    std::stringstream expected;
    expected  << "/ / / / / / / \t\tDAY:\t1\n"
              << "/ . . . . . / \t\tCurrent Seed:\tCarrot seeds\n"
              << "/ . . . . . / \t\tl:\tview controls\n"
              << "/ . . . . . / \t\ti:\tview inventory\n"
              << "/ . . . . . / \t\to:\tchange selected seed\n"
              << "/ . . P . . / \t\tp:\tplant selected seed\n"
              << "/ / / / / / / \t\tq:\tquit the game\n";
    REQUIRE(printer.prettyPrint_Game() == expected.str());
}
TEST_CASE( "game printer produces the legend." ) {
    inventory inventory_test;
    Carrot carrot;
    produce carrot_produce(&carrot);
    seeds carrot_seeds(&carrot);
    carrot.link_this_class(&carrot_seeds, &carrot_produce, &inventory_test);
    inventory_test.add_item(&carrot_seeds);
    Player p;
    p.set_bounds(5, 5);
    p.better_start_position();
    Farm farm(5, 5);
    farm.link_Player(&p);
    FarmPrinter printer_farm(&farm);
    GamePrinter printer(&printer_farm, &inventory_test);
    std::stringstream expected;
    expected     << "CONTROLS\n"
                 << "w:\tmove up\n"
                 << "s:\tmove down\n"
                 << "a:\tmove left\n"
                 << "d:\tmove right\n"
                 << "i:\tview inventory\n"
                 << "p:\tplant selected seed\n"
                 << "o:\tchange selected seed\n"
                 << "h:\tharvest grown crop\n"
                 << "e:\tend the day\n"
                 << "q:\tquit the game\n"
                 << "r:\treturn to the game\n";
    printer.generate_legend();
    REQUIRE(printer.prettyPrint_Legend() == expected.str());
}
TEST_CASE( "game printer produces the inventory." ) {
    inventory inventory_test;
    Carrot carrot;
    produce carrot_produce(&carrot);
    seeds carrot_seeds(&carrot);
    carrot.link_this_class(&carrot_seeds, &carrot_produce, &inventory_test);
    inventory_test.add_item_X_times(&carrot_seeds, 9);
    inventory_test.add_item_X_times(&carrot_produce, 3);
    Melon melon;
    produce melon_produce(&melon);
    seeds melon_seeds(&melon);
    melon.link_this_class(&melon_seeds, &melon_produce, &inventory_test);
    inventory_test.add_item_X_times(&melon_seeds, 22);
    inventory_test.add_item_X_times(&melon_produce, 30);
    Player p;
    p.set_bounds(5, 5);
    p.better_start_position();
    Farm farm(5, 5);
    farm.link_Player(&p);
    FarmPrinter printer_farm(&farm);
    GamePrinter printer(&printer_farm, &inventory_test);
    std::stringstream expected;
    expected     << "INVENTORY\n"
                 << "1:\tCarrot seeds, \t9x\n"
                 << "2:\tCarrot(s), \t3x\n"
                 << "3:\tMelon seeds, \t22x\n"
                 << "4:\tMelon(s), \t30x\n"
                 << "r:\treturn to the game\n";
    printer.generate_inventory();
    REQUIRE(printer.prettyPrint_Inventory() == expected.str());
}