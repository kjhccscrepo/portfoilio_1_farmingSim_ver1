#pragma once
#include <string>
#include <vector>
#include <sstream>
#include "player.hpp"
#include "farm.hpp"


class farm_brain {
private:
    farm *myFarm;
    player *myPlayer;
    int posRow;
    int posColumn;
    int day_count;

    std::vector<std::vector<std::string>> farm_stream;

public:
    farm_brain(farm *specifyFarm, player *specifyPlayer);
    std::string printFarm() const;
    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();
    void update_afterMove();
    void update_afterEndDay();
    std::string getSymbol(const int &x, const int &y) const;
    void generate_printer();
};
