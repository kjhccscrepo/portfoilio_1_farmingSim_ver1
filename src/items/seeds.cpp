#include "seeds.hpp"
seeds::seeds(plant *plant_ptr) {
    myPlant = plant_ptr;
    myName = (myPlant->myName() + " seeds");
    amount = 0;
}
std::string seeds::getMyName() {
    return myName;
}
void seeds::increase_quantity() {
    amount++;
}
void seeds::decrease_quantity() {
    amount--;
}
bool seeds::isSeed() {
    return true;
}
int seeds::quantity() {
    return amount;
}
Plot *seeds::pointer() {
    return myPlant;
}