#ifndef ITEM_H
#define ITEM_H
#include <string>
class plant;

// abstract base class
class item {
public:
    virtual ~item() = default;

    virtual std::string getMyName() = 0;

    virtual bool isSeed() = 0;

    virtual void increase_quantity() = 0;

    virtual void decrease_quantity() = 0;

    virtual int quantity() = 0;

    virtual plant *pointer() = 0;

    virtual int getCost();

    virtual void setCost(int &cost) = 0;

};
#endif
