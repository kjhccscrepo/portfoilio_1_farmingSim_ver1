#pragma once
#include "item.hpp"
#include "plants.hpp"

class produce final : public item {
private:
    plant *myPlant;
    std::string myName;
    int amount;
public:
    explicit produce(plant *plant_ptr);
    std::string getMyName() override;
    void increase_quantity() override;
    void decrease_quantity() override;
    bool isSeed() override;
    int quantity() override;
    Plot *pointer() override;
};