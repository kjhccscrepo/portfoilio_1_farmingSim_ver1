#ifndef SEEDS_H
#define SEEDS_H
#include "../item.hpp"


class seeds : public item {
private:
    plant *myPlant;
    std::string myName;
    int amount;
    int myCost;

public:
    explicit seeds(plant *plant_ptr);

    std::string getMyName() override;

    void increase_quantity() override;

    void decrease_quantity() override;

    bool isSeed() override;

    int quantity() override;

    plant *pointer() override;

    int getCost() override;

    void setCost(int &cost) override;

    ~seeds() override;
};
#endif
