#pragma once
#include <vector>
#include "farm_brain.hpp"
#include "plants.hpp"

class player {
private:
    // invitory goes here.

    char avatar = 'P';
public:
    //bound checking or some shit.
    player();

    char getAvatar();
};