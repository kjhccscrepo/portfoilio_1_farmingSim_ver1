#pragma once
#include "items.hpp"
#include "plants.hpp"

class seeds : public items {
private:
    friend class plants;
    plants *myPlant;
public:
    explicit seeds(const std::string &name, plants *plant_ptr);


    plants *getMyPlant();
};