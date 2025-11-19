//
// Created by kistj on 11/18/2025.
//

#ifndef FARMING_SIMULATOR_V2C_ZUCCHINI_HPP
#define FARMING_SIMULATOR_V2C_ZUCCHINI_HPP
#include <string>
#include <vector>
#include "../plant.hpp"

class Zucchini final : public plant {
public:
    Zucchini() {
        setName("Zucchini");
        setAge(1);
        setMatureTime(2);
        setWeightedStates({1});
        setStates({"x", "Z"});
        setSeedDrops({1, 2});
        setWeightedOddsSeeds({70, 30});
        setProduceDrops({1, 2});
        setWeightedOddsProduces({90, 10});
        setCost(2);
    }
};
#endif //FARMING_SIMULATOR_V2C_ZUCCHINI_HPP