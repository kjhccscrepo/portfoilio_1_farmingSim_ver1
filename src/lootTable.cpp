#include "lootTable.hpp"

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