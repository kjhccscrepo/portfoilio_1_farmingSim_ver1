#pragma once
#include <string>
#include "plants.hpp"
#include "seeds.hpp"

class soil {
private:
    int grade;
    std::string myName;
    std::string myDisplay;
    plants *myPlant;
    bool isOccupied;
public:
    explicit soil(const int &gradeTier, const std::string &name);
    explicit soil();
    void assignSeed(seeds *initializeSeed);

    void end_day();

    void tick();
    void harvest();
    std::string getDisplay() const;
    ~soil();
};