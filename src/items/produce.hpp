#ifndef PRODUCE_H
#define PRODUCE_H
#include "../item.hpp"
#include "../farm_and_friends/plant.hpp"

class produce : public item {
private:
    plant *myPlant;
    std::string myName;
    int amount;
    int mySell;

public:
    explicit produce(plant *plant_ptr);

    std::string getMyName() override;

    void increase_quantity() override;

    void decrease_quantity() override;

    bool isSeed() override;

    int quantity() override;

    plant *pointer() override;

    int getCost() override;

    void setCost(int &cost) override;

    ~produce() override;
};
#endif
