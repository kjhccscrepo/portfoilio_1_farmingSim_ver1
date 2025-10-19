#pragma once

class lootTable {
public:
    explicit lootTable(const int &min, const int &max, const int &dropChance, const int &weightedOdds);
    int minimumDropAmount;
    int maximumDropAmount;
    int dropChancePeak;
    int weightedOddsOnBottom;
    lootTable();
};