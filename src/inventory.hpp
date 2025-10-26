#ifndef INVENTORY_H
#define INVENTORY_H
#include <vector>
#include <sstream>
#include <algorithm>
#include "../src/plant.hpp"
#include "../src/item.hpp"

class inventory {
    std::vector<item*> myInventory;
public:
    int has(item *item_ptr);
    void add_item(item *item_ptr);
    void add_item_X_times(item *item_ptr, const int &i);
    bool can_remove(item *item_ptr);
    void remove_item(item *item_ptr);
    [[nodiscard]] std::stringstream inventory_stream() const;
    void move_item_to_front(const int &x);
    [[nodiscard]] bool is_first_item_plantable() const;
    [[nodiscard]] std::string first_name() const;
    [[nodiscard]] int mySize() const;
    [[nodiscard]] bool is_X_item_plantable(int x) const;
    void remove_1_seed() const;
    [[nodiscard]] plant *pointer_to_plant() const;
    [[nodiscard]] int how_many_types_of_things() const;
    [[nodiscard]] std::string getSelectedSeed() const;
};
#endif
