#ifndef FARM_H
#define FARM_H
#include <string>
#include <vector>
#include "../src/plot.hpp"
#include "../src/player.hpp"
#include "../src/soil.hpp"

class Farm {
private:
    int rows;
    int columns;
    Player *myPlayer;
    int dayCounter;
    std::vector<std::vector<Plot*>> plots;
public:
    Farm(int ini_rows, int ini_columns, Player *player_ptr);
    int harvest_val();
    [[nodiscard]] int row_capacity() const;
    [[nodiscard]] int column_capacity() const;
    [[nodiscard]] std::string get_symbol(int x, int y);
    [[nodiscard]] int getDays() const;
    void plant(int row, int column, Plot *plot);
    void end_day();
    void set_soil();
};
#endif