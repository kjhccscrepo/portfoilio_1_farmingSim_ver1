#include "farm_brain.hpp"

farm_brain::farm_brain(farm *specifyFarm, player *specifyPlayer) {
    this->myPlayer = specifyPlayer;
    this->myFarm = specifyFarm;
    this->yUpBound = this->myFarm->getYUpBound();
    this->yDownBound = 0;
    this->xUpBound = this->myFarm->getXUpBound();
    this->xDownBound = 0;
    this->posColumn = 0;
    this->posRow = 0;
}

std::string farm_brain::printFarm() {
    return "temp";
}

void farm_brain::moveRight() {
    posRow += 1;
}

void farm_brain::moveLeft() {
    posRow += -1;
}

void farm_brain::moveUp() {
    posColumn += 1;
}

void farm_brain::moveDown() {
    posColumn += -1;
}

void farm_brain::update() {
    for (int x = 0; x < this->xUpBound; x++) {
        for (int y = 0; y < this->yUpBound; y++) {
            if (posRow == x && posColumn == y) {
                brainPrint[x][y] = myPlayer->getAvatar();
            }
            brainPrint[x][y] = this->myFarm->getSymbol(x, y);
        }
    }

}

std::string farm_brain::getSymbol(const int &x, const int &y) {
if (x == posRow && y == posColumn) {
    return std::to_string(myPlayer->getAvatar());
}
    return std::to_string(this->myFarm->getSymbol(x, y));
}
