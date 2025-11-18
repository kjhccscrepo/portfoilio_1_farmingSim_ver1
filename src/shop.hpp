#ifndef SHOP_H
#define SHOP_H
#include "inventory.hpp"
#include "item.hpp"
#include "../src/items/seeds.hpp"
#include "../src/items/produce.hpp"
#include "../src/inventory.hpp"
#include "../src/ansi_clear.hpp"

class Shop {
    std::vector<seeds *> allSeeds;
    inventory *inventory_ptr;
    std::string playerName;

    int has(seeds *seed_ptr);

    int waterCanUpgradePrices[5] = {50, 120, 300, 760, 2146};
    bool broughtWUPS[5] = {false};

    int waterCan() const;

    void waterCanUpgrade_purchase();

public:
    Shop();

    void link(inventory *player_inventory, const std::string &name);

    void new_seed(seeds *seed_ptr);

    std::string welcome() const;

    static std::string menu_options();

    std::string buy_options() const;

    std::string sell_options() const;

    static std::string goodbye();

    void gotoShop();
};
#endif
