#include <iostream>
#include <random>
#include "src/ansi_clear.hpp"
#include "src/plants/carrot.hpp"
#include "src/plants/melon.hpp"
#include "src/plants/onion.hpp"
#include "src/farm.hpp"
#include "src/farm_printer.hpp"
#include "src/game_printer.hpp"
#include "src/inventory.hpp"
#include "src/item.hpp"
#include "src/plants.hpp"
#include "src/player.hpp"
#include "src/seeds.hpp"
#include "src/produce.hpp"
#include "src/soil.hpp"

int main() {
    inventory playerInventory;
    Soil soil;
    Carrot carrot;
    seeds seeds_Carrot(&carrot);
    produce produce_carrots(&carrot);
    carrot.link_this_class(&seeds_Carrot, &produce_carrots, &playerInventory);
    Melon melon;
    seeds seeds_Melon(&melon);
    produce produce_melon(&melon);
    melon.link_this_class(&seeds_Melon, &produce_melon, &playerInventory);
    Onion onion;
    seeds seeds_Onion(&onion);
    produce produce_Onion(&onion);
    onion.link_this_class(&seeds_Onion, &produce_Onion, &playerInventory);
    playerInventory.add_item_X_times(&seeds_Carrot, 5);
    playerInventory.add_item(&seeds_Melon);
    playerInventory.add_item(&seeds_Onion);
    Player game_player(&playerInventory, "P");
    Farm game_farm(7, 8, &game_player);
    game_player.set_bounds(game_farm.row_capacity(), game_farm.column_capacity());
    FarmPrinter farm_printer(&game_farm);
    GamePrinter game_printer(&farm_printer, &game_player);
    bool game_in_progress = true;
    std::string player_input;
    srand(time(nullptr));
    while(game_in_progress) {
        bool in_menus = false;
        ansi_clear();
        std::cout << game_printer.prettyPrint_Game() << std::endl;
        std::cin >> player_input;
        if(player_input == "q") { // exits game
            game_in_progress = false;
        } else if(player_input == "w") { // move up
            game_player.move_up();
        } else if(player_input == "a") { // move left
            game_player.move_left();
        } else if(player_input == "d") { // move right
            game_player.move_right();
        } else if(player_input == "s") { // move down
            game_player.move_down();
        } else if(player_input == "p") { // plant
            if (game_farm.harvest_val() == 1) { // it is soil and can be planted!
                if (playerInventory.is_first_item_plantable()) { // a seed has been selected and verified!
                    game_farm.plant(game_player.row(), game_player.column(), playerInventory.pointer_to_plot());
                    playerInventory.remove_1_seed();
                }
            }
        } else if (player_input == "h") { // harvest
            if (game_farm.harvest_val() == 3) { // 3 means it can and will be harvested
                game_farm.set_soil();
            }
        } else if (player_input == "o") { // change seed
            in_menus = true;
            game_printer.generate_inventory();
            while (in_menus) {
                ansi_clear();
                std::cout << game_printer.prettyPrint_Inventory() << std::endl;
                std::cout << "enter r to cancel, or...\n";
                std::cout << "Select an appropriate seed by entering its slot in your inventory.";
                std::cout << std::endl;
                std::cin >> player_input;
                if(player_input == "r") {
                    in_menus = false;
                } else if (std::stoi(player_input) <= 1 && std::stoi(player_input) >= (playerInventory.mySize())) {
                    if (playerInventory.is_X_item_plantable(std::stoi(player_input) - 1)) {
                        playerInventory.move_item_to_front(std::stoi(player_input) - 1);
                        in_menus = false;
                    } else {
                        std::cout << "invalid selection\n";
                    }
                }
            }

        } else if(player_input == "e") { // tick day
            game_farm.end_day();
        } else if (player_input == "i") { // show inventory
            in_menus = true;
            game_printer.generate_inventory();
            while (in_menus) {
                ansi_clear();
                std::cout << game_printer.prettyPrint_Inventory() << std::endl;
                std::cin >> player_input;
                if(player_input == "r") {
                    in_menus = false;
                }
            }
        } else if (player_input == "l") {
            in_menus = true;
            game_printer.generate_legend();
            while (in_menus) {
                ansi_clear();
                std::cout << game_printer.prettyPrint_Legend() << std::endl;
                std::cin >> player_input;
                if(player_input == "r") {
                    in_menus = false;
                }
            }

        }
    }
    return 0;
}