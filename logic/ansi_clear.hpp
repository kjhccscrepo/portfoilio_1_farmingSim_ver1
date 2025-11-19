//
// Created by kistj on 11/18/2025.
//

#ifndef FARMING_SIMULATOR_V2C_ANSI_CLEAR_HPP
#define FARMING_SIMULATOR_V2C_ANSI_CLEAR_HPP
#include <iostream>

inline void ansi_clear() {
    std::cout << "\033[2J\033[H";
}
#endif //FARMING_SIMULATOR_V2C_ANSI_CLEAR_HPP