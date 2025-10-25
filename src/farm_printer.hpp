#pragma once

#include <string>
#include <sstream>
#include "farm.hpp"


class FarmPrinter {
private:
    Farm *farm_to_print;
public:
    explicit FarmPrinter(Farm *farm_ptr);
    [[nodiscard]] std::stringstream prettyPrint() const;
};
