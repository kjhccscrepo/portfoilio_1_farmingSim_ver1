#ifndef PRODUCE_H
#define PRODUCE_H
#include "../item.hpp"
#include "../farm_and_friends/plant.hpp"
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
    plant *pointer() override;
};
#endif