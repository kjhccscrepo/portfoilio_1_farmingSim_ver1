#ifndef CUPID_H
#define CUPID_H
// this class handles setup for the game,
// and it pairs the classes.
#include "ansi_clear.hpp"
#include "farm.hpp"
#include "game_printer.hpp"
#include "inventory.hpp"
#include "player.hpp"
#include "shop.hpp"
#include "../src/soil.hpp"
#include "items/seeds.hpp"
#include "plants/beet.hpp"

class cupid {
private:
    inventory playerInventory;
    Soil soil;
    Player player;
    Farm farm;
    Shop shop;
    std::vector<seeds *> seed_unlockables;
    bool seeds_unlocked[3] = {false};
    bool in_menus = false;

    void try_plant();

    void seed_change(GamePrinter *printer, std::string &input);

    void inventory_peek(GamePrinter *printer, std::string &input);

    void legend_peek(GamePrinter *printer, std::string &input);

    void weed_time();

    void end_day();

    void water();

public:
    cupid();

    void runGame();
};
#endif
