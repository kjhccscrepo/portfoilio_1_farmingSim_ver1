#ifndef SEEDS_H
#define SEEDS_H
#include "../item.hpp"
#include "../plant.hpp"
class seeds final : public item {
private:
    plant *myPlant;
    std::string myName;
    int amount;
public:
    explicit seeds(plant *plant_ptr);
    std::string getMyName() override;
    void increase_quantity() override;
    void decrease_quantity() override;
    bool isSeed() override;
    int quantity() override;
    plant *pointer() override;
};
#endif
