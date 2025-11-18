#include "weed_classic.hpp"

weed_classic::weed_classic(Farm *ptr, int x, int y) {
    farm_ptr = ptr;
    w_X = x;
    w_Y = y;
}

std::string weed_classic::symbol() {
    return sym;
}

std::string weed_classic::myName() {
    return name;
}

void weed_classic::end_day() {
    if (farm_ptr == nullptr) {
        throw std::invalid_argument("farm_ptr is null");
    }
    // check down
    if (w_Y - 1 != 0) {
        if (farm_ptr->get_symbol(w_X, w_Y - 1) == "~") {
            farm_ptr->plant(w_X, w_Y - 1, this);
        }
        else {
            if (const int r = (rand() % (99)) + 1; r > 15) {
                farm_ptr->plant(w_X, w_Y - 1, this);
            }
        }
    }
    // check up
    if (w_Y + 1 != farm_ptr->column_capacity()) {
        if (farm_ptr->get_symbol(w_X, w_Y + 1) == "~") {
            farm_ptr->plant(w_X, w_Y + 1, this);
        }
        else {
            if (const int r = (rand() % (99)) + 1; r > 15) {
                farm_ptr->plant(w_X, w_Y + 1, this);
            }
        }
    }
    // check left
    if (w_X + 1 != 0) {
        if (farm_ptr->get_symbol(w_X - 1, w_Y) == "~") {
            farm_ptr->plant(w_X - 1, w_Y, this);
        }
        else {
            if (const int r = (rand() % (99)) + 1; r > 15) {
                farm_ptr->plant(w_X - 1, w_Y, this);
            }
        }
    }
    // check right
    if (w_X + 1 != farm_ptr->row_capacity()) {
        if (farm_ptr->get_symbol(w_X + 1, w_Y) == "~") {
            farm_ptr->plant(w_X + 1, w_Y, this);
        }
        else {
            if (const int r = (rand() % (99)) + 1; r > 15) {
                farm_ptr->plant(w_X + 1, w_Y, this);
            }
        }
    }
}

int weed_classic::harvest() {
    delete this;
    return -1;
}
