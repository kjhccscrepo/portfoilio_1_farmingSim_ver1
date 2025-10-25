#pragma once
#include <string>
#include <vector>
#include "../plants.hpp"
class Melon : public plant {
public:
    Melon() {
        name = "Melon";
        age = 1;
        mature_time = 8;
        myStates = {"p","o","O"};
        drop_amount_seed = {1, 2, 3, 4, 5, 6};
        weighted_odds_seeds = {10, 20, 30, 20, 10, 5};
        drop_amount_produce = {4, 5, 6, 7, 8, 9};
        weighted_odds_produce = {10, 20, 20, 15, 10, 5};
    }
};