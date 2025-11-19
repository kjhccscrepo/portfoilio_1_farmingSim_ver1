//
// Created by kistj on 11/18/2025.
//

#ifndef FARMING_SIMULATOR_V2C_SOIL_HPP
#define FARMING_SIMULATOR_V2C_SOIL_HPP

#include <string>
#include "plot.hpp"
class Plot;

class Soil final : public Plot {
public:
    std::string symbol() override;

    std::string myName() override;

    void end_day() override;

    int harvest() override;

    void water() override;

    item *seedPointer() override;

    item *producePointer() override;
};


#endif //FARMING_SIMULATOR_V2C_SOIL_HPP