#pragma once
#include <string>

class items {
private:
protected:
    std::string name;
    int quantity;
public:
    items();
    void modifyQuantity(int n);
    virtual ~items() = default;
};