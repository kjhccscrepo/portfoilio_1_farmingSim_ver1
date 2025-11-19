//
// Created by kistj on 11/18/2025.
//

#ifndef FARMING_SIMULATOR_V2C_PLOT_HPP
#define FARMING_SIMULATOR_V2C_PLOT_HPP
#include <string>
class item;
class inventory;

class Plot {
public:
    virtual ~Plot() = default;

    virtual std::string symbol() = 0;

    virtual std::string myName() = 0;

    virtual void end_day() = 0;

    virtual int harvest() = 0;

    virtual void water() = 0;

    virtual item *seedPointer() = 0;

    virtual item *producePointer() = 0;
};
#endif //FARMING_SIMULATOR_V2C_PLOT_HPP
