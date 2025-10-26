#ifndef FARM_PRINTER_H
#define FARM_PRINTER_H
#include <string>
#include <sstream>
#include "farm.hpp"


class FarmPrinter {
private:
    Farm *farm_to_print;
public:
    explicit FarmPrinter(Farm *farm_ptr);
    [[nodiscard]] std::stringstream prettyPrint() const;
    [[nodiscard]] int days_to_print() const;
};
#endif
