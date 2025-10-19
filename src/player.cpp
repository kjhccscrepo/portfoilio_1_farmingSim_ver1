#include "player.hpp"


player::player(std::vector<items> *inventory, const char avatar, const std::string &name) : myAvatar('P'), myName("John"){
    this->myInventory = inventory;
    this->myAvatar = avatar;
    this->myName = name;
    this->myMoney = 0;
}

char player::getAvatar() {
    return myAvatar;
}
