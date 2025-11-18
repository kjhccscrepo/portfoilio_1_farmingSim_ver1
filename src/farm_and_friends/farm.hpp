#ifndef FARM_H
#define FARM_H
#include <string>
#include <vector>
#include "plot.hpp"
#include "../player.hpp"
#include "../farm_and_friends/soil.hpp"

class Farm {
private:
    int rows;
    int columns;
    Player *myPlayer;
    int dayCounter;
    std::vector<std::vector<Plot*>> plots;
public:
    Farm(int ini_rows, int ini_columns);
    void link_Player(Player *player_ptr);
    int harvest_val() const;
    int harvest_val(int x, int y) const;
    int row_capacity() const;
    int column_capacity() const;
    std::string get_symbol(int x, int y) const;
    int getDays() const;
    void plant(int row, int column, Plot *plot);
    void end_day();
    void set_soil();
    void water_plot() const;

};
#endif