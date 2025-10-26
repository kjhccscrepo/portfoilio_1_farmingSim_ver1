#include "inventory.hpp"
int inventory::has(item *item_ptr) {
    if (item_ptr == nullptr) {
        return -3; // nullptr
    }
    if (std::ranges::find(myInventory, item_ptr) != myInventory.end()) {
        for (int position = 0; position < myInventory.size(); position++) {
            if (this->myInventory[position]->getMyName() == item_ptr->getMyName()) {
                return position;
            }
        } // not found after thought it was found, aka a false positive (yields a different result in case a bug pops up)
        return -2;
    } // not found, didn't think it found
    return -1;
}
void inventory::add_item(item *item_ptr) {
    int item_position = has(item_ptr);
    if (item_position >= 0) { // if this returns 0 or greater, then the item at that slot exists
        this->myInventory[item_position]->increase_quantity();
    } else { // else, the item does not yet exist in the inventory and must be added.
        this->myInventory.push_back(item_ptr);
        this->myInventory[myInventory.size() - 1]->increase_quantity();
    }
}
void inventory::add_item_X_times(item *item_ptr, const int &i) {
    int item_position = has(item_ptr);
    if (item_position >= 0) { // if this returns 0 or greater, then the item at that slot exists
        for (int j = 0; j < i; j++) {
            this->myInventory[item_position]->increase_quantity();
        }
    } else { // else, the item does not yet exist in the inventory and must be added.
        myInventory.push_back(item_ptr);
        for (int j = 0; j < i; j++) {
            this->myInventory[myInventory.size() - 1]->increase_quantity();
        }
    }
}
bool inventory::can_remove(item *item_ptr) {
    int item_position = has(item_ptr);
    if (item_position >= 0) {
        if (myInventory[item_position]->quantity() > 0) {
            return true;
        }
        return false;
    }
    return false;
}
void inventory::remove_item(item *item_ptr) {
    if (can_remove(item_ptr)) {
        int item_position = has(item_ptr);
        myInventory[item_position]->decrease_quantity();
    } // can't remove do don't do anything.
}
std::stringstream inventory::inventory_stream() const {
    std::stringstream inventoryStringStream;
    for (int i = 0; i < myInventory.size(); i++) {
        inventoryStringStream << myInventory[i]->getMyName();
        inventoryStringStream << ", \t";
        inventoryStringStream << myInventory[i]->quantity();
        inventoryStringStream << "x\n";
    }
    return inventoryStringStream;
}
void inventory::move_item_to_front(const int &x) {
    if (myInventory.size() > x) {
        std::ranges::rotate(myInventory, myInventory.begin() + x);
    }
}
bool inventory::is_first_item_plantable() const {
    if (myInventory[0]->isSeed()) {
        if (myInventory[0]->quantity() > 0) {
            return true;
        }
    }
    return false;
}
std::string inventory::first_name() const {
    return myInventory[0]->getMyName();
}
int inventory::mySize() const {
    return myInventory.size();
}
bool inventory::is_X_item_plantable(int x) const {
    if (myInventory[x]->isSeed()) {
        return true;
    }
    return false;
}
void inventory::remove_1_seed() const {
    myInventory[0]->decrease_quantity();
}
plant *inventory::pointer_to_plant() const {
    return dynamic_cast<plant *>(this->myInventory[0]->pointer());
}
int inventory::how_many_types_of_things() const {
    if (myInventory.empty()) {
        return 0;
    }
    return myInventory.size();
}
std::string inventory::getSelectedSeed() const {
    if (myInventory[0]->isSeed() && myInventory[0]->quantity() > 0) {
        return first_name();
    }
    return "none";
}