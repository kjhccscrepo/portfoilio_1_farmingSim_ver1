#pragma once
#include <string>
#include <vector>
#include "../plants.hpp"
class Carrot : public plant {
public:
    Carrot() {
        name = "Carrot";
        age = 1;
        mature_time = 3;
        myStates = {"v","V","W"};
        drop_amount_seed = {1, 2, 3};
        weighted_odds_seeds = {30, 40, 30};
        drop_amount_produce = {1, 2};
        weighted_odds_produce = {90, 10};
    }
};
