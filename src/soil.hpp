#ifndef SOIL_H
#define SOIL_H
#include <string>
#include "plot.hpp"

class Soil final : public Plot {
public:
    std::string symbol() override;

    std::string myName() override;

    void end_day() override;

    int harvest() override;

    void water() override;
};

#endif
