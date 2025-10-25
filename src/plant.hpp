#pragma once
#include <vector>
#include "item.hpp"
#include "inventory.hpp"
// base class for a plant.
class plant : public Plot {
public:
    std::string name;
    int age = 0;
    int mature_time = 0;
    std::vector<std::string> myStates;
    std::vector<int> drop_amount_seed;
    std::vector<int> weighted_odds_seeds;
    std::vector<int> drop_amount_produce;
    std::vector<int> weighted_odds_produce;
    item *my_seed = nullptr;
    item *my_produce = nullptr;
    inventory *my_inventory = nullptr;

    [[nodiscard]] bool isGrown() const;
    std::string symbol() override;
    void end_day() override;
    [[nodiscard]] int seedDrops() const;
    [[nodiscard]] int produceDrops() const;
    [[nodiscard]] std::string myName() const;
    static int sum_odds(const std::vector<int> &odds);
    static int oddsOffset(const int &iteration, const std::vector<int> &odds);
    void link_this_class(item *seed_pointer, item *produce_pointer, inventory *inventory_pointer);
    int harvest() override;
};
