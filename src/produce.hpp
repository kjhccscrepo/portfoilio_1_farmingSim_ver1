#pragma once
#include "items.hpp"

class produce : public item {
private:
    friend class plants;
public:
    explicit produce(const std::string &name);
};
