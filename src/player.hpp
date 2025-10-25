#pragma once
#include <string>
#include "inventory.hpp"

class Player {
private:
    int current_row;
    int current_column;
    std::string myAvatar;
    inventory *myStuff;
    int maxX;
    int maxY;

public:
    Player(inventory *playerStuff, const std::string &pAvatar);
    Player();
    [[nodiscard]] int getX() const;
    [[nodiscard]] int getY() const;
    void move_up();
    void move_down();
    void move_right();
    void move_left();
    void set_bounds(int xBound, int yBound);
    [[nodiscard]] std::string getInventoryString() const;
    [[nodiscard]] std::string getSelectedSeed() const;
    [[nodiscard]] std::string itemMove(const int &x) const;
    int how_many_types_of_things() const;
    std::string getAvatar();
    void setSeed(const int &x) const;
    void setUpCheck();
};
