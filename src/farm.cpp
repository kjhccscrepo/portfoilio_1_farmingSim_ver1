#include "farm.hpp"

farm::farm(int width, int depth) {
    farmland.resize(width);
    for (int i = 0; i < depth; i++) {
        farmland[i].resize(depth);
    }
    for (int j = 0; j < width; j++) {
        for (int k = 0; k < depth; k++) {
            farmland[j][k] = soil();
        }
    }
}

int farm::getYUpBound() {
    return farmland[0].size();
}

int farm::getXUpBound() {
    return farmland.size();
}

char farm::getSymbol(const int &x, const int &y) {
    return farmland[x][y].getDisplay();
}
