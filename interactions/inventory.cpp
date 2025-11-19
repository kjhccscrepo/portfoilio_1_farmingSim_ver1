//
// Created by kistj on 11/18/2025.
//

#include "inventory.hpp"

#include <algorithm>
#include <iostream>

inventory::inventory() {
    myMoney = 20;
    max_water = 5;
    current_water = max_water;
}

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
    if (item_position >= 0) {
        // if this returns 0 or greater, then the item at that slot exists
        this->myInventory[item_position]->increase_quantity();
    } else {
        // else, the item does not yet exist in the inventory and must be added.
        this->myInventory.push_back(item_ptr);
        this->myInventory[myInventory.size() - 1]->increase_quantity();
    }
}

void inventory::add_item_X_times(item *item_ptr, const int &i) {
    int item_position = has(item_ptr);
    if (item_position >= 0) {
        // if this returns 0 or greater, then the item at that slot exists
        for (int j = 0; j < i; j++) {
            this->myInventory[item_position]->increase_quantity();
        }
    } else {
        // else, the item does not yet exist in the inventory and must be added.
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
    }
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

std::string inventory::sell_stream() const {
    std::stringstream sellStream;
    for (int i = 0; i < myInventory.size(); i++) {
        sellStream << "x";
        sellStream << myInventory[i]->quantity();
        sellStream << "\t";
        sellStream << myInventory[i]->getMyName();
        sellStream << ", at $";
        sellStream << myInventory[i]->getCost();
        sellStream << "./n";
    }
    return sellStream.str();
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
    return (this->myInventory[0]->pointer());
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

std::string inventory::printMoney() const {
    return ("$" + std::to_string(myMoney));
}

int inventory::getMoney() const {
    return myMoney;
}

std::string inventory::buy_attempt(item *item_ptr, const int &amount = 1) {
    int total_price = item_ptr->getCost();
    total_price *= amount;
    if (total_price > myMoney) {
        return "You don't have enough money!\n";
    }
    myMoney -= total_price;
    add_item_X_times(item_ptr, amount);
    return ("Brought x" + std::to_string(amount) + " " + item_ptr->getMyName() + ", for $" + std::to_string(total_price)
            + ".\n");
}

std::string inventory::sell_attempt(const int &it, const int &amount) {
    if (it < 0 || it >= myInventory.size()) {
        return "You cannot sell that";
    }
    if (myInventory[it]->quantity() >= amount) {
        for (int i = 0; i < myInventory.size(); i++) {
            myInventory[it]->decrease_quantity();
            myMoney += myInventory[it]->getCost();
        }
        return "Sold " + std::to_string(amount) + " " + myInventory[it]->getMyName() + "(s)\n";
    }
    return "You cannot sell that much!\n";
}

std::string inventory::getNameOfItemX(const int &x) const {
    if (x >= 0) {
        if (x < myInventory.size()) {
            return myInventory[x]->getMyName();
        }
    }
    return "out of inventory bounds!!!";
}

int inventory::getAmountOfItemX(const int &x) const {
    if (x >= 0) {
        if (x < myInventory.size()) {
            return myInventory[x]->quantity();
        }
    }
    return -1;
}

void inventory::end_day() {
    current_water = max_water;
}

bool inventory::try_water() {
    if (current_water > 0) {
        current_water--;
        return true;
    }
    return false;
}

int inventory::getCurrentWater() const {
    return current_water;
}

void inventory::upgrade_water() {
    max_water += 2;
}

void inventory::loseMoney(const int n) {
    if (n <= myMoney) {
        myMoney -= n;
    } else {
        std::cout << "You don't have enough money!\n";
    }
}
