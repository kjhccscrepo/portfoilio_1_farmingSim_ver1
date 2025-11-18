#ifndef FARM_PRINTER_H
#define FARM_PRINTER_H
#include <sstream>
#include <string>
#include "farm.hpp"


class FarmPrinter {
private:
    Farm *farm_to_print;

public:
    explicit FarmPrinter(Farm *farm_ptr);

    std::stringstream prettyPrint() const;

    int days_to_print() const;
};
#endif