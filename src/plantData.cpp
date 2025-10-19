#include "plantData.hpp"

plantData::plantData(const int &growth, const std::string &name, const std::vector<char> &states) {
    this->timeToGrow = growth;
    this->name = name;
    this->states = states;
}

plantData::plantData() {
    this->timeToGrow = 0;
    this->name = "nullplant";
    this->states = {'}'};
}