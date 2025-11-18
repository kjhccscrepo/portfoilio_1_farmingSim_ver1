#ifndef INVENTORY_H
#define INVENTORY_H
#include <vector>
#include <sstream>
#include <algorithm>
#include "farm_and_friends/plant.hpp"
#include "../src/item.hpp"

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
    std::stringstream inventory_stream() const;
    std::string sell_stream() const;
    void move_item_to_front(const int &x);
    bool is_first_item_plantable() const;
    std::string first_name() const;
    int mySize() const;
    bool is_X_item_plantable(int x) const;
    void remove_1_seed() const;
    plant *pointer_to_plant() const;
    int how_many_types_of_things() const;
    std::string getSelectedSeed() const;

    std::string printMoney() const;
    int getMoney() const;
    std::string buy_attempt(item *item_ptr, const int &amount);
    std::string sell_attempt(const int &it, const int &amount);
    std::string getNameOfItemX(const int &x) const;
    int getAmountOfItemX(const int &x) const;

    void end_day();
    bool try_water();
    int getCurrentWater() const;
    void upgrade_water();
    void loseMoney(int n);
};
#endif
