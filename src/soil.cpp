#include "soil.hpp"
soil::soil(const int &gradeTier, const std::string &name) {
    this->grade = gradeTier;
    this->myName = name;
    this->isOccupied = false;
    myDisplay = '~';
}
soil::soil() {
    this->grade = 0;
    this->myName = "farmland";
    this->isOccupied = false;
    myDisplay = '~';
}
void soil::assignSeed(seeds *initializeSeed) {
    myPlant = new plants(*initializeSeed->getMyPlant());
    myDisplay = myPlant->getDisplay();
    isOccupied = true;
}

void soil::end_day() {
    tick();
}

void soil::tick() {
    if (myPlant != nullptr) {
        myPlant->tickUpdate();
        myDisplay = myPlant->getDisplay();
    } else {
        myDisplay = '~';
    }
}
void soil::harvest() {
    // code go here then....
    myPlant = nullptr;
}

char soil::getDisplay() {
    return myDisplay;
}

// this way the memory can be cleaned up I think....
soil::~soil() {
    delete myPlant;
}
