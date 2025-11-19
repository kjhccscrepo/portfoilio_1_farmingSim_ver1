//
// Created by kistj on 11/18/2025.
//

#ifndef FARMING_SIMULATOR_V2C_ONION_HPP
#define FARMING_SIMULATOR_V2C_ONION_HPP

#include <string>
#include <vector>
#include "../plant.hpp"

class Onion final : public plant {
public:
    Onion() {
        setName("Onion");
        setAge(1);
        setMatureTime(5);
        setWeightedStates({1, 3});
        setStates({"x", "y", "Y"});
        setSeedDrops({1, 2});
        setWeightedOddsSeeds({90, 10});
        setProduceDrops({2, 3, 4, 5, 6, 7});
        setWeightedOddsProduces({10, 20, 20, 15, 10, 5});
        setCost(5);
    }
};
#endif //FARMING_SIMULATOR_V2C_ONION_HPP