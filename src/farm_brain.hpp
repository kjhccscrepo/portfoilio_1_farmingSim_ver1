#pragma once
#include <string>
#include <vector>
#include "player.hpp"
#include "farm.hpp"


class farm_brain {
private:
    farm *myFarm;
    player myPlayer;
    int pos_playerX;
    int pos_playerY;
    int yUpBound;
    int yDownBound;
    int xUpBound;
    int xDownBound;
    int posRow;
    int posColumn;
    int day_count;

    std::vector <std::string> brainPrint;

public:
    farm_brain(farm *specifyFarm, player specifyPlayer);
    std::string printFarm();
    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();
    void update_afterAction();
    void update_afterEndDay();
    std::string getSymbol(const int &x, const int &y);



};
