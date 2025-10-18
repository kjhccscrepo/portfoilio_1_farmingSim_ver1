#include "items.hpp"

void item::modifyQuantity(int n) {
    this->quantity += n;
}
produce::produce(const std::string &name) {
    this->name = name;
}
seeds::seeds(const std::string &name) {
    this->name = name + " seeds";
}
