#pragma once
#include <vector>
#include "plants.hpp"
#include "items.hpp"

class player {
private:
    std::vector<items> *myInventory;
    char myAvatar;
    float myMoney;
    std::string myName;
    int x;
    int y;
public:
    explicit player(std::vector<items> *inventory, char avatar, const std::string &name);
    player();
    char getAvatar();

    int getY();
    int getX();

};