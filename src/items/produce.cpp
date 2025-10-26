#include "produce.hpp"
produce::produce(plant *plot_ptr) {
    myPlant = plot_ptr;
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
    return false;
}
int produce::quantity() {
    return amount;
}

plant *produce::pointer() {
    return myPlant;
}