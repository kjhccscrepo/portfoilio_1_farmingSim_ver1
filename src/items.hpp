#pragma once
#include <string>

class item {
private:
protected:
    std::string name;
    int quantity = 0;
public:
    void modifyQuantity(int n);
    virtual ~item() = default;
};

class produce : public item {
private:
    friend class plants;
public:
    explicit produce(const std::string &name);
};

class seeds : public item {
private:
    friend class plants;
public:
    explicit seeds(const std::string& name);

};
