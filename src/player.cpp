#include "player.hpp"
Player::Player(inventory *playerStuff, const std::string &pAvatar) {
    myStuff = playerStuff;
    myAvatar = pAvatar;
    current_row = 0;
    current_column = 0;
    maxX = 0;
    maxY = 0;
}
Player::Player() {
    myStuff = nullptr;
    myAvatar = "P";
    current_row = 0;
    current_column = 0;
    maxX = 0;
    maxY = 0;
}
int Player::getX() const {
    return this->current_row;
}
int Player::getY() const {
    return this->current_column;
}
void Player::move_up() {
    setUpCheck();
    if (this->current_column != 0) {
        this->current_column -= 1;
    }
}
void Player::move_down() {
    setUpCheck();
    if (this->current_column != this->maxY) {
        this->current_column += 1;
    }
}
void Player::move_right() {
    setUpCheck();
    if (this->current_row != this->maxX) {
        this->current_row += 1;
    }

}
void Player::move_left() {
    setUpCheck();
    if (this->current_row != 0) {
        this->current_row -= 1;
    }
}

void Player::set_bounds(int xBound, int yBound) {
    this->maxX = xBound - 1;
    this->maxY = yBound - 1;
}

std::string Player::getInventoryString() const {
    if (this->myStuff != nullptr) {
        return this->myStuff->inventory_stream().str();
    }
   return {};
}

std::string Player::getSelectedSeed() const {
    if (this->myStuff != nullptr) {
        if (this->myStuff->is_first_item_plantable()) {
            return this->myStuff->first_name();
        }
        return "none";
    }
    return "none";
}

std::string Player::itemMove(const int &x) const {
    if (this->myStuff != nullptr) {
        if (this->myStuff->is_X_item_plantable(x - 1)) {
            setSeed(x - 1);
            return (this->myStuff->first_name() + "chosen");
        }
        return "Invalid Selection!";
    }
    return "Invalid Selection!";
}

int Player::how_many_types_of_things() const {
    return myStuff->mySize();
}

std::string Player::getAvatar() {
    return this->myAvatar;
}

void Player::setSeed(const int &x) const {
    this->myStuff->move_item_to_front(x);
}

void Player::setUpCheck() {
    if (maxX == 0 || maxY == 0) {
    throw "player has unset max";
    }
}


