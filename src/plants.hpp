#pragma once
#include <string>
#include <vector>
#include "produce.hpp"
#include "lootTable.hpp"
#include "plantData.hpp"


class plants {
private:
    std::string myName;
    int myTimeToMature;
    std::vector<char> myStates;
    int ticks;
    bool canHarvest;
    char myDisplay;
    int getDisplayPosition() const;
    bool isGrown() const;
    lootTable plantHarvest;
    lootTable seedHarvest;

    produce *myProduct;

public:
    explicit plants(const plantData &data, lootTable harvestDrops, lootTable seedDrops);
    void tickUpdate();
    char getDisplay() const;
    plants *returnMe();

    produce returnProduce();
};
