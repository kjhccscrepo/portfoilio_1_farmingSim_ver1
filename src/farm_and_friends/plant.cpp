#include "../farm_and_friends/plant.hpp"


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
    const int rand_num = (rand() % (sum_odds(weighted_odds_seeds)));
    for (int i = 0; i < weighted_odds_seeds.size(); i++) {
        if (rand_num <= oddsOffset(i, weighted_odds_seeds)) {
            return drop_amount_seed[i];
        }
    }
    return 1; // if it somehow reaches the end
}

int plant::produceDrops() const {
    const int rand_num = (rand() % (sum_odds(weighted_odds_produce)));
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
    my_seed->setCost(cost);
    my_produce->setCost(cost);
    hasWater = false;
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
    if (weightedStates.empty()) {
        for (int i = 0; i < mature_time; i++) {
            myStates.push_back(set_states[(i * (myStates.size() - 1) / (mature_time))]);
        }
    } else {
        for (int m = 0; m < weightedStates.size(); m++) {
            for (int n = 0; n < weightedStates[m]; n++) {
                myStates.push_back(set_states[m]);
            }
        }
        if (myStates.size() != mature_time) {
            myStates.pop_back();
            for (int j = 0; j < mature_time - myStates.size(); j++) {
                myStates.push_back(set_states[set_states.size() - 2]);
            }
            myStates.push_back(set_states[set_states.size() - 1]);
        }
    }
}

void plant::setWeightedStates(const std::vector<int> &set_weighted_states) {
    weightedStates = set_weighted_states;
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

void plant::setCost(const int &myCost) {
    cost = myCost;
}

plant::plant(const plant *plant_ptr) {
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

void plant::water() {
    if (!hasWater) {
        hasWater = true;
    }
}

int plant::getCost() const {
    return cost;
}

void plant::end_day() {
    age += 1;
    if (hasWater) {
        age += 2;
        hasWater = false;
    }
}
