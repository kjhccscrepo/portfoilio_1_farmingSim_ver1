#ifndef BEET_H
#define BEET_H
#include <vector>
#include "../farm_and_friends/plant.hpp"
class Beet final : public plant {
public:
    Beet() {
        setName("Beet");
        setAge(1);
        setMatureTime(8);
        setWeightedStates({2, 5});
        setStates({"x","b","B"});

        setSeedDrops({1, 2});
        setWeightedOddsSeeds({30, 20});
        setProduceDrops({1, 2});
        setWeightedOddsProduces({40, 30});

        setCost(4);
    }
};
#endif
