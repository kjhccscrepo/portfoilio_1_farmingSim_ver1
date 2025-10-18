#pragma once
#include <vector>
#include "farm_brain.hpp"
#include "plants.hpp"
#include "items.hpp"

class player {
private:
    // inventory goes here.

    char avatar = 'P';
public:
    //bound checking or some shit.
    player();

    char getAvatar();
};