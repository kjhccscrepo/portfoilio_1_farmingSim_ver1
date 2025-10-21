#include "player.hpp"


player::player(std::vector<items> *inventory, const char avatar, const std::string &name) : myAvatar('P'), myName("John"){
    this->myInventory = inventory;
    this->myAvatar = avatar;
    this->myName = name;
    this->myMoney = 0;
}

player::player() {
    this->myInventory = new std::vector<items>;
    this->myAvatar = 'P';
    this->myName = "John";
    this->myMoney = 0;
}

char player::getAvatar() {
    return myAvatar;
}

int player::getY() {
    return y;
}
int player::getX() {
    return x;
}
