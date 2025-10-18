#pragma once
#include <string>
#include <vector>

class plantData {
public:
    plantData(const int &growth, const std::string &name, const std::vector<char> &states);
    int timeToGrow;
    std::string name;
    std::vector<char> states;
    plantData();
};
class lootTable {
public:
    lootTable(const int &min, const int &max, const int &dropChance, const int &weightedOdds);
    int minimumDropAmount;
    int maximumDropAmount;
    int dropChancePeak;
    int weightedOddsOnBottom;
    lootTable();
};

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
public:
    explicit plants(const plantData &data, lootTable harvestDrops, lootTable seedDrops);
    void tickUpdate();
    char getDisplay() const;
};
