#ifndef LETTUCE_H
#define LETTUCE_H
#include <vector>
#include "../farm_and_friends/plant.hpp"

class Lettuce final : public plant {
public:
    Lettuce() {
        setName("Lettuce");
        setAge(1);
        setMatureTime(5);
        setStates({"x", "l", "L"});
        setSeedDrops({1});
        setWeightedOddsSeeds({100});
        setProduceDrops({1});
        setWeightedOddsProduces({100});
        setCost(8);
    }
};
#endif