//
// Created by kistj on 11/18/2025.
//

#ifndef FARMING_SIMULATOR_V2C_MELON_HPP
#define FARMING_SIMULATOR_V2C_MELON_HPP
#include <string>
#include <vector>
#include "../plant.hpp"

class Melon final : public plant {
public:
    Melon() {
        setName("Melon");
        setAge(1);
        setMatureTime(8);
        setWeightedStates({1, 3, 3});
        setStates({"x", ".", "o", "O"});
        setSeedDrops({1, 2, 3, 4, 5, 6});
        setWeightedOddsSeeds({10, 20, 30, 20, 10, 5});
        setProduceDrops({4, 5, 6, 7, 8, 9});
        setWeightedOddsProduces({10, 20, 20, 15, 10, 5});
        setCost(4);
    }
};
#endif //FARMING_SIMULATOR_V2C_MELON_HPP