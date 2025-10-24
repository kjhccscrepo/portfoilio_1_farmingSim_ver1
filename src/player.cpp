#include "player.hpp"


player::player(std::vector<items> *inventory, const std::string &avatar, const std::string &name) : myAvatar("P"), myName("John"){
    this->myInventory = inventory;
    this->myAvatar = avatar;
    this->myName = name;
    this->myMoney = 0;
    this->x = 0;
    this->y = 0;
}

player::player() {
    this->myInventory = new std::vector<items>;
    this->myAvatar = "P";
    this->myName = "John";
    this->myMoney = 0;
    this->x = 0;
    this->y = 0;
}

std::string player::getAvatar() const {
    return myAvatar;
}

int player::getY() const {
    return y;
}
int player::getX() const {
    return x;
}
