#pragma once
#include "items.hpp"

class produce : public items {
private:
    friend class plants;

public:
    explicit produce(const std::string &name);
};
