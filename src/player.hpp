#pragma once
#include <vector>
#include "farm_brain.hpp"
#include "plants.hpp"
#include "items.hpp"

class player {
private:
    std::vector<items> *myInventory;
    char myAvatar;
    float myMoney;
    std::string myName;
public:
    explicit player(std::vector<items> *inventory, char avatar, const std::string &name);
    char getAvatar();
};