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
void soil::assignSeed(const plants *initializeSeed) {
    *mySeed = *initializeSeed;
    myDisplay = mySeed->getDisplay();
    isOccupied = true;
}
void soil::tick() {
    if (mySeed != nullptr) {
        mySeed->tickUpdate();
        myDisplay = mySeed->getDisplay();
    } else {
        myDisplay = '~';
    }
}
void soil::harvest() {

}

char soil::getDisplay() {
    return myDisplay;
}
