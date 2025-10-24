#pragma once
#include <vector>
#include "soil.hpp"

class farm {
private:
    std::vector<std::vector<soil>> farmland;
public:
    farm(int x, int y);
    int getYUpBound() const;
    int getXUpBound() const;
    std::string getSymbol(const int &x, const int &y) const;
    void end_FarmDay();

};
