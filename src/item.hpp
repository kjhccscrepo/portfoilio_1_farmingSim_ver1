#pragma once
#include <string>
#include "Plot.hpp"
// abstract base class
class item {
public:
    virtual ~item() = default;
    virtual std::string getMyName() = 0;
    virtual bool isSeed() = 0;
    virtual void increase_quantity() = 0;
    virtual void decrease_quantity() = 0;
    virtual int quantity() = 0;
    virtual Plot *pointer();
};