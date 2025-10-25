#include "player.hpp"
Player::Player(const std::string &pAvatar) {
    myAvatar = pAvatar;
    current_x = 0;
    current_y = 0;
    maxX = 0;
    maxY = 0;
}
Player::Player() {
    myAvatar = "P";
    current_x = 0;
    current_y = 0;
    maxX = 0;
    maxY = 0;
}
int Player::getX() const {
    return this->current_x;
}
int Player::getY() const {
    return this->current_y;
}
void Player::move_up() {
    setUpCheck();
    if (this->current_y != 0) {
        this->current_y -= 1;
    }
}
void Player::move_down() {
    setUpCheck();
    if (this->current_y != this->maxY) {
        this->current_y += 1;
    }
}
void Player::move_right() {
    setUpCheck();
    if (this->current_x != this->maxX) {
        this->current_x += 1;
    }

}
void Player::move_left() {
    setUpCheck();
    if (this->current_x != 0) {
        this->current_x -= 1;
    }
}
void Player::set_bounds(int xBound, int yBound) {
    this->maxX = xBound - 1;
    this->maxY = yBound - 1;
}
std::string Player::getAvatar() {
    return this->myAvatar;
}
void Player::setUpCheck() {
    if (maxX == 0 || maxY == 0) {
    throw "player has unset max";
    }
}
void Player::better_start_position() {
    setUpCheck();
    this->current_y = maxY;
    this->current_x = (maxX / 2);
}
void Player::change_avatar(char n) {
    myAvatar = std::to_string(n);
}