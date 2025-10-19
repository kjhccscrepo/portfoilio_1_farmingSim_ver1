#include "items.hpp"

items::items() {
    quantity = 0;
}

void items::modifyQuantity(int n) {
    this->quantity += n;
}

