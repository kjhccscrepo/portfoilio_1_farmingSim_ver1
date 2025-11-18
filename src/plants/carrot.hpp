#ifndef CARROT_H
#define CARROT_H
#include <vector>
#include "../plant.hpp"

class Carrot final : public plant {
public:
    Carrot() {
        name = "Carrot";
        age = 1;
        mature_time = 3;
        myStates = {"x", "w", "W"};
        cost = 3;
        setSeedDrops({1, 2, 3});
        setWeightedOddsSeeds({30, 40, 30});
        setProduceDrops({1, 2});
        setWeightedOddsProduces({90, 10});

    }
};
#endif