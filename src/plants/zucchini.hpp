#pragma once
#include <string>
#include <vector>
#include "../plant.hpp"
class Zucchini : public plant {
public:
    Zucchini() {
        name = "Zucchini";
        age = 1;
        mature_time = 2;
        myStates = {"z","Z"};
        drop_amount_seed = {1, 2};
        weighted_odds_seeds = {70, 30};
        drop_amount_produce = {1, 2};
        weighted_odds_produce = {90, 10};
    }
};
