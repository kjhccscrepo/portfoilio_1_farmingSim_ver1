#include "soil.hpp"
soil::soil(const int &gradeTier, const std::string &name) {
    this->grade = gradeTier;
    this->myName = name;
    this->isOccupied = false;
    this->myPlant = nullptr;
    this->myDisplay = "~";
}
soil::soil() {
    this->grade = 0;
    this->myName = "farmland";
    this->isOccupied = false;
    this->myPlant = nullptr;
    this->myDisplay = "~";
}
void soil::assignSeed(seeds *initializeSeed) {
    this->myPlant = new plants(*initializeSeed->getMyPlant());
    this->myDisplay = this->myPlant->getDisplay();
    this->isOccupied = true;
}

void soil::end_day() {
    tick();
}

void soil::tick() {
    if (this->myPlant != nullptr) {
        this->myPlant->tickUpdate();
        this->myDisplay = this->myPlant->getDisplay();
    } else {
        this->myDisplay = "~";
    }
}
void soil::harvest() {
    // code go here then....
    this->myPlant = nullptr;
}

std::string soil::getDisplay() const {
    return myDisplay;
}

// this way the memory can be cleaned up I think....
soil::~soil() {
    delete myPlant;
}
