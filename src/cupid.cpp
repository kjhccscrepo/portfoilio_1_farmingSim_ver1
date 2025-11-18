#include "cupid.hpp"

void cupid::try_plant() {
    if (playerInventory.is_first_item_plantable()) {
        // a seed has been selected and verified!
        plant *new_plant = new plant(playerInventory.pointer_to_plant());
        farm.plant(player.getX(), player.getY(), new_plant);
        playerInventory.remove_1_seed();
    }
}

void cupid::seed_change(GamePrinter *printer, std::string &input) {
    in_menus = true;
    printer->generate_inventory();
    while (in_menus) {
        ansi_clear();
        std::cout << "enter r to cancel, or...\n";
        std::cout << printer->prettyPrint_Inventory() << std::endl;
        std::cout << "Select an appropriate seed by entering its slot in your inventory.";
        std::cout << std::endl;
        std::cin >> input;
        if (input == "r") {
            in_menus = false;
        } else if (isdigit(input.front())) {
            if (std::stoi(input) > 0 && std::stoi(input) <= (playerInventory.mySize())) {
                if (playerInventory.is_X_item_plantable(std::stoi(input) - 1)) {
                    playerInventory.move_item_to_front(std::stoi(input) - 1);
                    in_menus = false;
                }
            } else {
                std::cout << "invalid selection\n";
            }
        }
    }
}

void cupid::inventory_peek(GamePrinter *printer, std::string &input) {
    in_menus = true;
    printer->generate_inventory();
    while (in_menus) {
        ansi_clear();
        std::cout << printer->prettyPrint_Inventory() << std::endl;
        std::cin >> input;
        if (input == "r") {
            in_menus = false;
        }
    }
}

void cupid::legend_peek(GamePrinter *printer, std::string &input) {
    in_menus = true;
    printer->generate_legend();
    while (in_menus) {
        ansi_clear();
        std::cout << printer->prettyPrint_Legend() << std::endl;
        std::cin >> input;
        if (input == "r") {
            in_menus = false;
        }
    }
}

void cupid::weed_time() {
    const int r = (rand() % 99) + 1;
    int w = 0;
    if (r == 100) {
        w++;
        w++;
    }
    if (r >= 75) {
        w++;
    }
    if (r >= 55) {
        w++;
    }
    if (r >= 40) {
        w++;
    }
    if (r >= 25) {
        w++;
    }
    while (w != 0) {
        const int x = rand() % (farm.row_capacity() - 1);
        const int y = rand() % (farm.column_capacity() - 1);
        if (farm.get_symbol(x, y) == "~") {
            weed_classic *weed_ptr = new weed_classic(&farm, x, y);
            farm.plant(x, y, weed_ptr);
        } else if (farm.get_symbol(x, y) != "*") {
            const int o = (rand() % 9) + 1;
            if (o > 6) {
                weed_classic *weed_ptr = new weed_classic(&farm, x, y);
                farm.plant(x, y, weed_ptr);
            }
        }
        w--;
    }
}


void cupid::end_day() {
    farm.end_day();
    playerInventory.end_day();
    weed_time();

    if (!seeds_unlocked[2]) {
        if (farm.getDays() > 30) {
            seeds_unlocked[2] = true;
            shop.new_seed(seed_unlockables[2]);
        }
    } else if (!seeds_unlocked[1]) {
        if (farm.getDays() > 13) {
            seeds_unlocked[1] = true;
            shop.new_seed(seed_unlockables[1]);
        }
    } else if (!seeds_unlocked[0]) {
        if (farm.getDays() > 13) {
            seeds_unlocked[0] = true;
            shop.new_seed(seed_unlockables[0]);
        }
    }
}

void cupid::water() {
    if (playerInventory.try_water()) {
        farm.water_plot();
    }
}

cupid::cupid() : farm(9, 11) {
}

void cupid::runGame() {
    //plants
    Carrot carrot;
    Melon melon;
    Onion onion;
    Zucchini zucchini;
    Beet beet;
    Brussels_Sprouts brussels_sprouts;
    Lettuce lettuce;
    Spinach spinach;
    // seed setup.
    seeds seeds_Carrot(&carrot);
    seeds seeds_Melon(&melon);
    seeds seeds_Onion(&onion);
    seeds seeds_Zucchini(&zucchini);
    seeds seeds_Beet(&beet);
    seeds seeds_Brussels(&brussels_sprouts);
    seeds seeds_Lettuce(&lettuce);
    seeds seeds_Spinach(&spinach);
    // unlockables
    seed_unlockables.push_back(&seeds_Melon);
    seed_unlockables.push_back(&seeds_Onion);
    seed_unlockables.push_back(&seeds_Zucchini);
    // produce setup.
    produce produce_carrot(&carrot);
    produce produce_melon(&melon);
    produce produce_onion(&onion);
    produce produce_zucchini(&zucchini);
    produce produce_beet(&beet);
    produce produce_brussels(&brussels_sprouts);
    produce produce_lettuce(&lettuce);
    produce produce_spinach(&spinach);
    //class linking
    carrot.link_this_class(&seeds_Carrot, &produce_carrot, &playerInventory);
    melon.link_this_class(&seeds_Melon, &produce_melon, &playerInventory);
    onion.link_this_class(&seeds_Onion, &produce_onion, &playerInventory);
    zucchini.link_this_class(&seeds_Zucchini, &produce_zucchini, &playerInventory);
    beet.link_this_class(&seeds_Beet, &produce_beet, &playerInventory);
    brussels_sprouts.link_this_class(&seeds_Brussels, &produce_brussels, &playerInventory);
    lettuce.link_this_class(&seeds_Lettuce, &produce_lettuce, &playerInventory);
    spinach.link_this_class(&seeds_Spinach, &produce_spinach, &playerInventory);
    //shop setup
    shop.link(&playerInventory, "Farmer");

    shop.new_seed(&seeds_Carrot);
    shop.new_seed(&seeds_Beet);
    shop.new_seed(&seeds_Lettuce);
    shop.new_seed(&seeds_Spinach);
    shop.new_seed(&seeds_Brussels);

    //initial inventory setup
    playerInventory.add_item_X_times(&seeds_Carrot, 2);
    playerInventory.add_item_X_times(&seeds_Beet, 4);
    playerInventory.add_item_X_times(&seeds_Lettuce, 1);
    playerInventory.add_item_X_times(&seeds_Spinach, 3);
    playerInventory.add_item_X_times(&seeds_Brussels, 7);
    farm.link_Player(&player);
    player.set_bounds(farm.row_capacity(), farm.column_capacity());
    player.better_start_position();
    FarmPrinter farm_printer(&farm);
    GamePrinter game_printer(&farm_printer, &playerInventory);
    bool game_in_progress = true;
    std::string player_input;
    srand(time(nullptr));
    while (game_in_progress) {
        ansi_clear();
        std::cout << game_printer.prettyPrint_Game() << std::endl;
        std::cin >> player_input;
        if (player_input == "q") {
            // exits game
            game_in_progress = false;
            std::cout << "\nThank you for playing!\n";
        } else if (player_input == "w") {
            // move up
            player.move_up();
        } else if (player_input == "a") {
            // move left
            player.move_left();
        } else if (player_input == "d") {
            // move right
            player.move_right();
        } else if (player_input == "s") {
            // move down
            player.move_down();
        } else if (player_input == "p") {
            // plant
            if (farm.harvest_val() == 1) {
                // it is soil and can be planted!
                try_plant();
            }
        } else if (player_input == "h") {
            // harvest
            if (farm.harvest_val() == 3) {
                // 3 means it can and will be harvested
                farm.set_soil();
            }
        } else if (player_input == "o") {
            // change seed
            seed_change(&game_printer, player_input);
        } else if (player_input == "e") {
            // tick day
            end_day();
        } else if (player_input == "i") {
            // show inventory
            inventory_peek(&game_printer, player_input);
        } else if (player_input == "l") {
            legend_peek(&game_printer, player_input);
        } else if (player_input == "q") {
            water();
        } else if (player_input == "m") {
            shop.gotoShop();
        }
    }
}
