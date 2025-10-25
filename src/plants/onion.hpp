#pragma once
#include <string>
#include <vector>
#include "../plants.hpp"
class Onion : public plant {
public:
    Onion() {
        name = "Onion";
        age = 1;
        mature_time = 5;
        myStates = {"y","Y"};
        drop_amount_seed = {1, 2};
        weighted_odds_seeds = {90, 10};
        drop_amount_produce = {2, 3, 4, 5, 6, 7};
        weighted_odds_produce = {10, 20, 20, 15, 10, 5};
    }
};
