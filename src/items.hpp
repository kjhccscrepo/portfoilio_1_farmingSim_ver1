#pragma once
#include <string>

class item {
private:
protected:
    std::string name;
    int quantity;
public:
    item();
    void modifyQuantity(int n);
    virtual ~item() = default;
};