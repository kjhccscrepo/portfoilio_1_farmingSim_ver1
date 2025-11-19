//
// Created by kistj on 11/18/2025.
//

#ifndef PORFOLIO_2_CS122_BEET_HPP
#define PORFOLIO_2_CS122_BEET_HPP
#include <vector>
#include "../plant.hpp"
class Beet final : public plant {
public:
    Beet() {
        name = "Beet";
        age = 1;
        mature_time = 8;
        weightedStates = {2, 5};
        setStates({"x", "b", "B"});
        cost = 4;
        setSeedDrops({1, 2});
        setWeightedOddsSeeds({30, 20});
        setProduceDrops({1, 2});
        setWeightedOddsProduces({40, 30});
    }
};



#endif