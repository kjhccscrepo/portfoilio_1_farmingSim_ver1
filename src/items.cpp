#include "items.hpp"

item::item() {
    quantity = 0;
}

void item::modifyQuantity(int n) {
    this->quantity += n;
}

