#include "farm_brain.hpp"
#include "player.hpp"


farm_brain::farm_brain(farm *specifyFarm, player *specifyPlayer) {
    this->myPlayer = specifyPlayer;
    this->myFarm = specifyFarm;
    this->posColumn = 0;
    this->posRow = 0;
    this->day_count = 0;
    farm_stream.resize(this->myFarm->getXUpBound() + 2);
    for (int x = 0; x < this->myFarm->getXUpBound() + 2; x++) {
        farm_stream[x].resize(this->myFarm->getYUpBound() + 2);
    }
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

void farm_brain::update_afterMove() {
    for (int x = 0; x < this->farm_stream.size(); x++) {
        for (int y = 0; y < this->farm_stream[x].size(); y++) {
            if (this->myPlayer->getX() == x && this->myPlayer->getY() == y) {
                this->farm_stream[x][y] = this->myPlayer->getAvatar();
            }
        }
    }

}

void farm_brain::update_afterEndDay() {
    myFarm->end_FarmDay();
    day_count++;
    update_afterMove();
}

std::string farm_brain::getSymbol(const int &x, const int &y) const {
if (x == posRow && y == posColumn) {
    return (this->myPlayer->getAvatar());
}
    return (this->myFarm->getSymbol(x, y));
}

void farm_brain::generate_printer() {
    // generates the top border!
    for (int x = 0; x < farm_stream.size(); x++) {
        farm_stream[x][0] = "/";
    }
    farm_stream[farm_stream.size() - 1][0] = "/\n";
    // generates the bottom border!
    for (int x = 0; x < farm_stream[0].size(); x++) {
        farm_stream[x][farm_stream[0].size() - 1] = "/";
    }
    farm_stream[farm_stream.size() - 1][farm_stream[0].size() - 1] = "/\n";
    // generates the left and right border.
    for (int y = 0; y < farm_stream[0].size() - 1; y++) {
        farm_stream[0][y + 1] = "/";
        farm_stream[farm_stream.size() - 1][y + 1] = "/\n";
    }

    // makes the farm
    for (int y = farm_stream[0].size() - 2; y > 0; y--) {
        for (int x = 0; x < farm_stream[0].size() - 2; x++) {
            farm_stream[x + 1][y + 1] = getSymbol(x, y);
        }
    }
}

std::string farm_brain::printFarm() const {
    std::stringstream brain_stringstream;
    for (int x = 0; x < this->farm_stream.size(); x++) {
        for (int y = 0; y < this->farm_stream[x].size(); y++) {
            brain_stringstream << this->farm_stream[x][y];
        }
    }
    return brain_stringstream.str();
}

