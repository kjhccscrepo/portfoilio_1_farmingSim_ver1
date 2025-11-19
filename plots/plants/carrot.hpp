//
// Created by kistj on 11/18/2025.
//

#ifndef FARMING_SIMULATOR_V2C_CARROT_HPP
#define FARMING_SIMULATOR_V2C_CARROT_HPP

#include <vector>
#include "../plant.hpp"

class Carrot final : public plant {
public:
    Carrot() {
        name = "Carrot";
        age = 1;
        mature_time = 3;
        setWeightedStates({1, 1});
        setStates({"x", "w", "W"});
        cost = 3;
        setSeedDrops({1, 2, 3});
        setWeightedOddsSeeds({30, 40, 30});
        setProduceDrops({1, 2});
        setWeightedOddsProduces({90, 10});

    }
};
#endif //FARMING_SIMULATOR_V2C_CARROT_HPP