#pragma once
#include <string>
#include "plants.hpp"
#include "seeds.hpp"

class soil {
private:
    int grade;
    std::string myName;
    char myDisplay;
    plants *myPlant;
    bool isOccupied;
public:
    explicit soil(const int &gradeTier, const std::string &name);
    soil();
    void assignSeed(seeds *initializeSeed);

    void end_day();

    void tick();
    void harvest();
    char getDisplay();
    ~soil();
};