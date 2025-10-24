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
    std::vector<std::string> myStates;
    int ticks;
    bool canHarvest;
    std::string myDisplay;
    int getDisplayPosition() const;
    bool isGrown() const;
    lootTable plantHarvest;
    lootTable seedHarvest;

    produce *myProduct;

public:
    explicit plants(const plantData &data, lootTable harvestDrops, lootTable seedDrops);
    void tickUpdate();

    std::string getDisplay() const;
    plants *returnMe();

    produce returnProduce() const;
};
