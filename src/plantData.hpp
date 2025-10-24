#pragma once
#include <string>
#include <vector>
class plantData {
public:
    explicit plantData(const int &growth, const std::string &name, const std::vector<std::string> &states);
    int timeToGrow;
    std::string name;
    std::vector<std::string> states;
    plantData();
};