#include "farm.hpp"

farm::farm(int x, int y) {
    this->farmland.resize(x);
    for (int iX = 0; iX < x; iX++) {
        this->farmland[iX].resize(y);
    }
}

int farm::getXUpBound() const {
    return farmland.size();
}
int farm::getYUpBound() const {
    return farmland[0].size();
}
std::string farm::getSymbol(const int &x, const int &y) const {
    return farmland[x][y].getDisplay();
}

void farm::end_FarmDay() {
    for (int i = 0; i < farmland.size(); i++) {
        for (int j = 0; j < farmland[i].size(); j++) {
            farmland[i][j].end_day();
        }
    }
}
