#ifndef PLANT_H
#define PLANT_H
#include <vector>
#include "inventory.hpp"
#include "item.hpp"
#include "plot.hpp"

// base class for a plant.
class plant : public Plot {
public:
    std::string name;
    int age{1};
    int mature_time{2};
    std::vector<std::string> myStates;
    std::vector<int> drop_amount_seed;
    std::vector<int> weighted_odds_seeds;
    std::vector<int> drop_amount_produce;
    std::vector<int> weighted_odds_produce;
    item *my_seed{nullptr};
    item *my_produce{nullptr};
    inventory *my_inventory{nullptr};
    ~plant() override = default;
    [[nodiscard]] bool isGrown() const;
    std::string symbol() override;
    void end_day() override;
    [[nodiscard]] int seedDrops() const;
    [[nodiscard]] int produceDrops() const;
    std::string myName() override;
    static int sum_odds(const std::vector<int> &odds);
    static int oddsOffset(const int &iteration, const std::vector<int> &odds);
    void link_this_class(item *seed_pointer, item *produce_pointer, inventory *inventory_pointer);
    int harvest() override;
    void setName(const std::string &set_name);
    void setAge(const int &set_age);
    void setMatureTime(const int &set_mature_time);
    void setStates(const std::vector<std::string> &set_states);
    void setSeedDrops(const std::vector<int> &set_drop_amount_seed);
    void setWeightedOddsSeeds(const std::vector<int> &set_weighted_odds_seeds);
    void setProduceDrops(const std::vector<int> &set_drop_amount_produce);
    void setWeightedOddsProduces(const std::vector<int> &set_weighted_odds_produce);
    plant() = default;
    explicit plant(plant *plant_ptr);
};
#endif