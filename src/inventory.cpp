#include "inventory.hpp"
int inventory::has(item *item_ptr) {
    if (item_ptr == nullptr) {
        return -3; // nullptr
    }
    if (std::find(myInventory.begin(), myInventory.end(), item_ptr) != myInventory.end()) {
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
    if (item_position >= 0) { // if this returns 0 or greater, then the item at that slot exists
        if (myInventory.at(item_position)->quantity() > 0) {
            return true;
        } // if it has less than 1, it cannot be taken anymore
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
std::stringstream inventory::inventory_stream() {
    std::stringstream inventoryStringStream;
    for (int i = 0; i < myInventory.size(); i++) {
        inventoryStringStream << myInventory[i]->getMyName();
        inventoryStringStream << ", ";
        inventoryStringStream << myInventory[i]->quantity();
        inventoryStringStream << "x\n";
    }
    return inventoryStringStream;
}
void inventory::move_item_to_front(const int &x) {
    if (myInventory.size() > x) {
        std::rotate(myInventory.begin(), myInventory.begin() + x, myInventory.end());
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

void inventory::remove_1_seed() {
    myInventory[0]->decrease_quantity();
}

Plot *inventory::pointer_to_plot() {
    return this->myInventory[0]->pointer();
}
