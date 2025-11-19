//
// Created by kistj on 11/18/2025.
//

#ifndef FARMING_SIMULATOR_V2C_INVENTORY_HPP
#define FARMING_SIMULATOR_V2C_INVENTORY_HPP

#include <sstream>
#include <vector>
#include "item.hpp"
class item;
class plant;

class inventory {
    std::vector<item*> myInventory;
    int myMoney;
    int max_water;
    int current_water;

public:
    inventory();

    int has(item *item_ptr);

    void add_item(item *item_ptr);

    void add_item_X_times(item *item_ptr, const int &i);

    bool can_remove(item *item_ptr);

    void remove_item(item *item_ptr);

    [[nodiscard]] std::stringstream inventory_stream() const;

    [[nodiscard]] std::string sell_stream() const;

    void move_item_to_front(const int &x);

    [[nodiscard]] bool is_first_item_plantable() const;

    [[nodiscard]] std::string first_name() const;

    [[nodiscard]] int mySize() const;

    [[nodiscard]] bool is_X_item_plantable(int x) const;

    void remove_1_seed() const;

    [[nodiscard]] plant *pointer_to_plant() const;

    [[nodiscard]] int how_many_types_of_things() const;

    [[nodiscard]] std::string getSelectedSeed() const;

    [[nodiscard]] std::string printMoney() const;

    [[nodiscard]] int getMoney() const;

    std::string buy_attempt(item *item_ptr, const int &amount);

    std::string sell_attempt(const int &it, const int &amount);

    [[nodiscard]] std::string getNameOfItemX(const int &x) const;

    [[nodiscard]] int getAmountOfItemX(const int &x) const;

    void end_day();

    bool try_water();

    [[nodiscard]] int getCurrentWater() const;

    void upgrade_water();

    void loseMoney(int n);
};

#endif //FARMING_SIMULATOR_V2C_INVENTORY_HPP