#pragma once
#include <string>
#include "farm.hpp"
#include "player.hpp"

class farm_brain {
private:
    farm *myFarm;
    player *myPlayer;
    int yUpBound;
    int yDownBound;
    int xUpBound;
    int xDownBound;
    int posRow;
    int posColumn;

    std::vector <std::string> brainPrint;

public:
    farm_brain(farm *specifyFarm, player *specifyPlayer);
    std::string printFarm();
    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();
    void update();
    std::string getSymbol(const int &x, const int &y);



};
