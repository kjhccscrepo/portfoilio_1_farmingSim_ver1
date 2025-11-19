//
// Created by kistj on 11/18/2025.
//

#ifndef FARMING_SIMULATOR_V2C_SEEDS_HPP
#define FARMING_SIMULATOR_V2C_SEEDS_HPP

#include "../../plots/plant.hpp"
#include "../item.hpp"
#include "../../plots/plot.hpp"

class seeds final : public item {
private:
    plant *myPlant;
    std::string myName;
    int amount;
    int myCost;

public:
    ~seeds() override;

    explicit seeds(plant *plant_ptr);

    std::string getMyName() override;

    void increase_quantity() override;

    void decrease_quantity() override;

    bool isSeed() override;

    int quantity() override;

    plant *pointer() override;

    int getCost() override;

    void setCost(int &cost) override;

};
#endif //FARMING_SIMULATOR_V2C_SEEDS_HPP