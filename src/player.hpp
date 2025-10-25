#pragma once
#include <string>
#include "inventory.hpp"

class Player {
private:
    int current_x;
    int current_y;
    std::string myAvatar;
    int maxX;
    int maxY;
public:
    Player(const std::string &pAvatar);
    Player();
    [[nodiscard]] int getX() const;
    [[nodiscard]] int getY() const;
    void move_up();
    void move_down();
    void move_right();
    void move_left();
    void set_bounds(int xBound, int yBound);
    std::string getAvatar();
    void setUpCheck();
    void better_start_position();
    void change_avatar(char n);
};
