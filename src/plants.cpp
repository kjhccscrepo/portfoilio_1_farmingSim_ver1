#include "plants.hpp"



int plants::getDisplayPosition() const {
    return (ticks / myTimeToMature) * (myStates.size() - 1);
}
bool plants::isGrown() const {
    if (ticks <= myTimeToMature) {
        return true;
    }
    return false;
}

plants::plants(const plantData &data, lootTable harvestDrops, lootTable seedDrops) {
    this->plantHarvest = harvestDrops;
    this->seedHarvest = seedDrops;
    this->myTimeToMature = data.timeToGrow;
    this->myName = data.name;
    this->myStates = data.states;
    ticks = 0;
    canHarvest = false;
    myDisplay = myStates[0];
    this->myProduct = new produce(data.name);
}


void plants::tickUpdate() {
    if (!isGrown()) {
        ticks++;
        myDisplay = myStates[getDisplayPosition()];
        if (isGrown()) {
            canHarvest = true;
        }
    }
}

std::string plants::getDisplay() const {
    return myDisplay;
}

plants *plants::returnMe() {
    return this;
}

produce plants::returnProduce() const {
    return *myProduct;
}

