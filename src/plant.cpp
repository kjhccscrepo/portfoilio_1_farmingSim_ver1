#include "plant.hpp"



bool plant::isGrown() const {
    if (age >= mature_time) {
        return true;
    }
    return false;
}
std::string plant::symbol() {
    if (!isGrown()) {
        return myStates[(age * (myStates.size() - 1) / (mature_time))];
    }
    return myStates[(myStates.size() - 1)];
}
int plant::seedDrops() const {
    int rand_num = (rand() % (sum_odds(weighted_odds_seeds)));
    for (int i = 0; i < weighted_odds_seeds.size(); i++) {
        if (rand_num <= oddsOffset(i, weighted_odds_seeds)) {
            return drop_amount_seed[i];
        }
    }
    return 1; // if it somehow reaches the end
}

int plant::produceDrops() const {
    int rand_num = (rand() % (sum_odds(weighted_odds_produce)));
    for (int i = 0; i < weighted_odds_produce.size(); i++) {
        if (rand_num <= oddsOffset(i, weighted_odds_produce)) {
            return drop_amount_produce[i];
        }
    }
    return 1; // if it somehow reaches the end
}

std::string plant::myName() {
    return name;
}
int plant::sum_odds(const std::vector<int> &odds) {
    int sum = 0;
    for (int i = 0; i < odds.size(); i++) {
        sum += odds[i];
    }
    return sum;
}
int plant::oddsOffset(const int &iteration, const std::vector<int> &odds) {
    int offset = 0;
    for (int i = 0; i <= iteration; i++) {
        offset += odds[i];
    }
    return offset;
}

void plant::link_this_class(item *seed_pointer, item *produce_pointer, inventory *inventory_pointer) {
    my_seed = seed_pointer;
    my_produce = produce_pointer;
    my_inventory = inventory_pointer;
}

int plant::harvest() {
    if (isGrown()) {
        this->my_inventory->add_item_X_times(my_seed, seedDrops());
        this->my_inventory->add_item_X_times(my_produce, produceDrops());
        return 3;
    }
    return 2;
}

void plant::setName(const std::string &set_name) {
    name = set_name;
}
void plant::setAge(const int &set_age) {
    age = set_age;
}
void plant::setMatureTime(const int &set_mature_time) {
    mature_time = set_mature_time;
}
void plant::setStates(const std::vector<std::string> &set_states) {
    myStates = set_states;
}
void plant::setSeedDrops(const std::vector<int> &set_drop_amount_seed) {
    drop_amount_seed = set_drop_amount_seed;
}
void plant::setWeightedOddsSeeds(const std::vector<int> &set_weighted_odds_seeds) {
    weighted_odds_seeds = set_weighted_odds_seeds;
}
void plant::setProduceDrops(const std::vector<int> &set_drop_amount_produce) {
    drop_amount_produce = set_drop_amount_produce;
}
void plant::setWeightedOddsProduces(const std::vector<int> &set_weighted_odds_produce) {
    weighted_odds_produce = set_weighted_odds_produce;
}
plant::plant(plant *plant_ptr) {
    this->setName(plant_ptr->name);
    this->setAge(plant_ptr->age);
    this->setMatureTime(plant_ptr->mature_time);
    this->setStates(plant_ptr->myStates);
    this->drop_amount_seed = (plant_ptr->drop_amount_seed);
    this->weighted_odds_seeds = (plant_ptr->weighted_odds_seeds);
    this->drop_amount_produce = (plant_ptr->drop_amount_produce);
    this->weighted_odds_produce = (plant_ptr->weighted_odds_produce);
    this->my_seed = plant_ptr->my_seed;
    this->my_produce = plant_ptr->my_produce;
    this->my_inventory = plant_ptr->my_inventory;
}
void plant::end_day() {
    age += 1;
}
