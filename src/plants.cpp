#include "plants.hpp"

plantData::plantData(const int &growth, const std::string &name, const std::vector<char> &states) {
    this->timeToGrow = growth;
    this->name = name;
    this->states = states;
}

plantData::plantData() {
    this->timeToGrow = 0;
    this->name = " ";
    this->states = {' '};
}

lootTable::lootTable(const int &min, const int &max, const int &dropChance, const int &weightedOdds) {
    this->minimumDropAmount = min;
    this->maximumDropAmount = max;
    this->dropChancePeak = dropChance;
    this->weightedOddsOnBottom = weightedOdds;
}

lootTable::lootTable() {
    this->minimumDropAmount = 0;
    this->maximumDropAmount = 0;
    this->dropChancePeak = 0;
    this->weightedOddsOnBottom = 0;
}

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

char plants::getDisplay() const {
    return myDisplay;
}

