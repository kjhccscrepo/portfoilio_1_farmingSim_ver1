#ifndef WEED_H
#define WEED_H
#include "plot.hpp"

class Weed : public Plot {
    void water() override {
        // no-op
    }
    std::string symbol() override;

    std::string myName() override;

    void end_day() override;

    int harvest() override;
};
#endif
