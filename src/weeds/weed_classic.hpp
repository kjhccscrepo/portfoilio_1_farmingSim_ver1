#ifndef WEED_CLASSIC_H
#define WEED_CLASSIC_H
#include <random>
#include <string>
#include "../farm.hpp"

#include "../weed.hpp"

class weed_classic final : public Weed {
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
#endif