#pragma once
#include <vector>
#include "plants.hpp"
#include "items.hpp"

class player {
private:
    std::vector<items> *myInventory;
    std::string myAvatar;
    float myMoney;
    std::string myName;
    int x;
    int y;
public:
    explicit player(std::vector<items> *inventory, const std::string &avatar, const std::string &name);
    explicit player();
    std::string getAvatar() const;

    int getY() const;
    int getX() const;

};