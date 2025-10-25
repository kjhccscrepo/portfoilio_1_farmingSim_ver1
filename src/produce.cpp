#include "produce.hpp"

produce::produce(plant *plant_ptr) {
    myPlant = plant_ptr;
    myName = (myPlant->myName() + "(s)");
    amount = 0;
}
std::string produce::getMyName() {
    return myName;
}
void produce::increase_quantity() {
    amount++;
}
void produce::decrease_quantity() {
    amount--;
}
bool produce::isSeed() {
    return true;
}
int produce::quantity() {
    return amount;
}

Plot * produce::pointer() {
    return nullptr;
}
