#ifndef ZUCCHINI_H
#define ZUCCHINI_H
#include <string>
#include <vector>
#include "../farm_and_friends/plant.hpp"
class Zucchini final : public plant {
public:
    Zucchini() {
        setName("Zucchini");
        setAge(1);
        setMatureTime(2);
        setStates({"x","Z"});
        setSeedDrops({1, 2});
        setWeightedOddsSeeds({70, 30});
        setProduceDrops({1, 2});
        setWeightedOddsProduces({90, 10});
        setCost(2);
    }
};
#endif
