#include "seeds.hpp"

seeds::seeds(const std::string& name, plants *plant_ptr) {
    this->name = name + " seeds";
    this->myPlant = plant_ptr;
}

plants *seeds::getMyPlant() {
    return myPlant->returnMe();
}
