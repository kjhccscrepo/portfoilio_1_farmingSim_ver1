#ifndef CARROT_H
#define CARROT_H
#include <vector>
#include "../farm_and_friends/plant.hpp"
class Carrot final : public plant {
public:
    Carrot() {
        setName("Carrot");
        setAge(1);
        setMatureTime(3);
        setStates({"x","w","W"});
        setSeedDrops({1, 2, 3});
        setWeightedOddsSeeds({30, 40, 30});
        setProduceDrops({1, 2});
        setWeightedOddsProduces({90, 10});
    }
};
#endif
