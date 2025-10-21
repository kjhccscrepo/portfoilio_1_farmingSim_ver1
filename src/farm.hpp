#pragma once
#include <vector>
#include "soil.hpp"

class farm {
private:
    std::vector<std::vector<soil>> farmland;
public:
    farm(int width, int depth);
    int getYUpBound();
    int getXUpBound();
    char getSymbol(const int &x, const int &y);

    void end_FarmDay();

};
