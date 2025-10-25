#pragma once
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
    int getDays() const;
    void plant(int row, int column, Plot *plot);
    void end_day();
    void set_soil();
};
// to my understanding the [[nodiscard]] is mostly just here for MY compiler so that if I encounted runtime errors
//      during testing it will save that value and return keep it briefly so that I could more easily figure out
//      a problem.
