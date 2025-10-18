#pragma once
#include <string>
#include "plants.hpp"

class soil {
private:
    int grade;
    std::string myName;
    char myDisplay;
    plants *mySeed;
    bool isOccupied;
public:
    explicit soil(const int &gradeTier, const std::string &name);
    soil();
    void assignSeed(const plants *initializeSeed);
    void tick();
    void harvest();

    char getDisplay();

};