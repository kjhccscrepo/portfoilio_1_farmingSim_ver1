#pragma once
#include <vector>
#include <algorithm>
#include <sstream>
#include "../src/item.hpp"
#include "../src/plot.hpp"

class inventory {
    std::vector<item*> myInventory;
public:
    int has(item *item_ptr);
    void add_item(item *item_ptr);
    void add_item_X_times(item *item_ptr, const int &i);
    bool can_remove(item *item_ptr);
    void remove_item(item *item_ptr);
    std::stringstream inventory_stream();
    void move_item_to_front(const int &x);
    bool is_first_item_plantable() const;
    std::string first_name() const;
    [[nodiscard]] int mySize() const;
    bool is_X_item_plantable(int x) const;
    void remove_1_seed();
    Plot *pointer_to_plot();
};