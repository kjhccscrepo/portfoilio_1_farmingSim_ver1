#pragma once
#include "items.hpp"

class seeds : public item {
private:
    friend class plants;
public:
    explicit seeds(const std::string& name);

};