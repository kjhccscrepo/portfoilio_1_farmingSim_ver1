#ifndef PLOT_H
#define PLOT_H
#include <string>
class inventory;
class Plot {
public:
    virtual ~Plot() = default;
    virtual std::string symbol() = 0;
    virtual std::string myName() = 0;
    virtual void end_day() = 0;
    virtual int harvest() = 0;
};
#endif