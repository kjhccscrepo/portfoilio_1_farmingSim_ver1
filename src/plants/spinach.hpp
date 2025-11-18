#ifndef SPINACH_H
#define SPINACH_H
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
#endif