#ifndef CUPID_H
#define CUPID_H
// this class handles setup for the game,
// and it pairs the classes.

#include "inventory.hpp"
#include "farm_and_friends/soil.hpp"
#include "items/produce.hpp"
#include "items/seeds.hpp"
#include "plants/beet.hpp"
#include "plants/brussels_sprouts.hpp"
#include "plants/carrot.hpp"
#include "plants/lettuce.hpp"
#include "plants/melon.hpp"
#include "plants/onion.hpp"
#include "plants/spinach.hpp"
#include "plants/zucchini.hpp"
#include "game_printer.hpp"
#include "player.hpp"
#include "farm_and_friends/farm.hpp"
#include "ansi_clear.hpp"
#include "shop.hpp"
#include "farm_and_friends/weeds/weed_classic.hpp"

class cupid {
private:
    inventory playerInventory;
    Soil soil;
    Player player;
    Farm farm;
    Shop shop;
    std::vector<seeds*> seed_unlockables;
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
    explicit cupid();
    void runGame();
};
#endif