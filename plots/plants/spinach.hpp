//
// Created by kistj on 11/18/2025.
//

#ifndef FARMING_SIMULATOR_V2C_SPINACH_HPP
#define FARMING_SIMULATOR_V2C_SPINACH_HPP
#include <vector>
#include "../plant.hpp"

class Spinach final : public plant {
public:
    Spinach() {
        setName("Spinach");
        setAge(1);
        setMatureTime(6);
        setWeightedStates({2, 3});
        setStates({"x", "s", "S"});
        setSeedDrops({1, 2});
        setWeightedOddsSeeds({50, 50});
        setProduceDrops({3, 4, 5, 6});
        setWeightedOddsProduces({20, 30, 30, 10});
        setCost(3);
    }
};
#endif //FARMING_SIMULATOR_V2C_SPINACH_HPP