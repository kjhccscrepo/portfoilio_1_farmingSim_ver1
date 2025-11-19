//
// Created by kistj on 11/18/2025.
//

#ifndef FARMING_SIMULATOR_V2C_FARM_HPP
#define FARMING_SIMULATOR_V2C_FARM_HPP

#include <string>
#include <vector>
#include "player.hpp"
#include "../plots/plot.hpp"

class Farm {
private:
    int rows;
    int columns;
    Player *myPlayer;
    int dayCounter;
    std::vector<std::vector<Plot *> > plots;

public:
    explicit Farm(int ini_rows, int ini_columns);

    void link_Player(Player *player_ptr);

    [[nodiscard]] int harvest_val();

    [[nodiscard]] int harvest_val(int x, int y) const;

    [[nodiscard]] int row_capacity() const;

    [[nodiscard]] int column_capacity() const;

    [[nodiscard]] std::string get_symbol(int x, int y) const;

    [[nodiscard]] int getDays() const;

    void plant(int row, int column, Plot *plot);

    void end_day();

    void set_soil();

    void water_plot() const;

    Plot *current_plot() const;
};
#endif //FARMING_SIMULATOR_V2C_FARM_HPP