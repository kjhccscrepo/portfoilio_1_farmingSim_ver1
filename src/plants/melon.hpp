#ifndef MELON_H
#define MELON_H
#include <string>
#include <vector>
#include "../farm_and_friends/plant.hpp"

class Melon final : public plant {
public:
    Melon() {
        setName("Melon");
        setAge(1);
        setMatureTime(8);
        setStates({"x", "p", "O"});
        setSeedDrops({1, 2, 3, 4, 5, 6});
        setWeightedOddsSeeds({10, 20, 30, 20, 10, 5});
        setProduceDrops({4, 5, 6, 7, 8, 9});
        setWeightedOddsProduces({10, 20, 20, 15, 10, 5});

        setCost(2);
    }
};
#endif