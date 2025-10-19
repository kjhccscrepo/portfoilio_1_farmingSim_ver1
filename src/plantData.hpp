#pragma once
#include <string>
#include <vector>
class plantData {
public:
    explicit plantData(const int &growth, const std::string &name, const std::vector<char> &states);
    int timeToGrow;
    std::string name;
    std::vector<char> states;
    plantData();
};