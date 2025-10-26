#ifndef MAIN_H
#define MAIN_H
#include <iostream>
#include <random>
#include "src/ansi_clear.hpp"
#include "src/soil.hpp"
#include "src/item.hpp"
#include "src/plants/carrot.hpp"
#include "src/plants/melon.hpp"
#include "src/plants/onion.hpp"
#include "src/items/seeds.hpp"
#include "src/items/produce.hpp"
#include "src/inventory.hpp"
#include "src/farm.hpp"
#include "src/farm_printer.hpp"
#include "src/game_printer.hpp"
#include "src/player.hpp"
#include "src/plants/zucchini.hpp"
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
    Zucchini zucchini;
    seeds seeds_Zucchini(&zucchini);
    produce produce_Zucchini(&zucchini);
    zucchini.link_this_class(&seeds_Zucchini, &produce_Zucchini, &playerInventory);
    playerInventory.add_item_X_times(&seeds_Zucchini, 5);
    playerInventory.add_item_X_times(&seeds_Carrot, 2);
    playerInventory.add_item(&seeds_Melon);
    playerInventory.add_item(&seeds_Onion);
    Player p_Farmer;
    Farm farm_obj(7, 8, &p_Farmer);
    p_Farmer.set_bounds(farm_obj.row_capacity(), farm_obj.column_capacity());
    FarmPrinter farm_printer(&farm_obj);
    GamePrinter game_printer(&farm_printer, &playerInventory);
    p_Farmer.better_start_position();
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
            p_Farmer.move_up();
        } else if(player_input == "a") { // move left
            p_Farmer.move_left();
        } else if(player_input == "d") { // move right
            p_Farmer.move_right();
        } else if(player_input == "s") { // move down
            p_Farmer.move_down();
        } else if(player_input == "p") { // plant
            if (farm_obj.harvest_val() == 1) { // it is soil and can be planted!
                if (playerInventory.is_first_item_plantable()) { // a seed has been selected and verified!
                    plant *new_plant = new plant(playerInventory.pointer_to_plant());
                    farm_obj.plant(p_Farmer.getX(), p_Farmer.getY(), new_plant);
                    playerInventory.remove_1_seed();
                }
            }
        } else if (player_input == "h") { // harvest
            if (farm_obj.harvest_val() == 3) { // 3 means it can and will be harvested
                farm_obj.set_soil();
            }
        } else if (player_input == "o") { // change seed
            in_menus = true;
            game_printer.generate_inventory();
            while (in_menus) {
                ansi_clear();
                std::cout << "enter r to cancel, or...\n";
                std::cout << game_printer.prettyPrint_Inventory() << std::endl;
                std::cout << "Select an appropriate seed by entering its slot in your inventory.";
                std::cout << std::endl;
                std::cin >> player_input;
                if(player_input == "r") {
                    in_menus = false;
                } else if (isdigit(player_input.front())) {
                    if (std::stoi(player_input) > 0 && std::stoi(player_input) <= (playerInventory.mySize())) {
                        if (playerInventory.is_X_item_plantable(std::stoi(player_input) - 1)) {
                            playerInventory.move_item_to_front(std::stoi(player_input) - 1);
                            in_menus = false;
                        }
                    } else {
                        std::cout << "invalid selection\n";
                    }
                }
            }
        } else if(player_input == "e") { // tick day
            farm_obj.end_day();
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
#endif