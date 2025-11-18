#ifndef BEET_H
#define BEET_H
#include <vector>
#include "../farm_and_friends/plant.hpp"

class Beet final : public plant {
public:
    Beet() {
        name = "Beet";
        age = 1;
        mature_time = 8;
        weightedStates = {2, 5};
        myStates = {"x", "b", "B"};
        cost = 4;

        setSeedDrops({1, 2});
        setWeightedOddsSeeds({30, 20});
        setProduceDrops({1, 2});
        setWeightedOddsProduces({40, 30});
    }
};
#endif
