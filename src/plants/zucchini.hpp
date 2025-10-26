#ifndef ZUCCHINI_H
#define ZUCCHINI_H
#include <string>
#include <vector>
#include "../plant.hpp"
class Zucchini final : public plant {
public:
    Zucchini() {
        setName("Zucchini");
        setAge(1);
        setMatureTime(2);
        setStates({"z","Z"});
        setSeedDrops({1, 2});
        setWeightedOddsSeeds({70, 30});
        setProduceDrops({1, 2});
        setWeightedOddsProduces({90, 10});
    }
};
#endif
