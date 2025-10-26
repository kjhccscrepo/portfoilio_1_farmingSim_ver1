#ifndef ONION_H
#define ONION_H
#include <string>
#include <vector>
#include "../plant.hpp"
class Onion final : public plant {
public:
    Onion() {
        setName("Onion");
        setAge(1);
        setMatureTime(5);
        setStates({"y","Y"});
        setSeedDrops({1, 2});
        setWeightedOddsSeeds({90, 10});
        setProduceDrops({2, 3, 4, 5, 6, 7});
        setWeightedOddsProduces({10, 20, 20, 15, 10, 5});
    }
};
#endif