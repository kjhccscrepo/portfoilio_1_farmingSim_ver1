//
// Created by kistj on 11/18/2025.
//

#ifndef FARMING_SIMULATOR_V2C_WEED_CLASSIC_HPP
#define FARMING_SIMULATOR_V2C_WEED_CLASSIC_HPP
#include <random>
#include <string>
#include "../../farm_stuff/farm.hpp"
#include "../plot.hpp"

class weed_classic final : public Plot {
private:
    std::string name = "Common Weed";
    std::string sym = "*";
    Farm *farm_ptr;
    int w_X;
    int w_Y;

public:
    explicit weed_classic(Farm *ptr, int x, int y);

    std::string symbol() override;

    std::string myName() override;

    void end_day() override;

    int harvest() override;

    void water() override;

    ~weed_classic() override;
};

#endif //FARMING_SIMULATOR_V2C_WEED_CLASSIC_HPP