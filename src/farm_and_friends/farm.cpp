#include "../farm_and_friends/farm.hpp"

Farm::Farm(const int ini_rows, const int ini_columns) {
    myPlayer = nullptr;
    rows = ini_rows;
    columns = ini_columns;
    for(int i = 0; i < ini_rows; i++) {
        std::vector<Plot *> row;
    for(int j = 0; j < ini_columns; j++) {
        Soil *soil = new Soil();
        row.push_back(soil);
        }
    plots.push_back(row);
    }
  dayCounter = 1;
}

void Farm::link_Player(Player *player_ptr) {
  myPlayer = player_ptr;
}

int Farm::harvest_val() const {
    if (plots[myPlayer->getX()][myPlayer->getY()] != nullptr) {
      return plots[myPlayer->getX()][myPlayer->getY()]->harvest();
    }
  return 0;
}

int Farm::harvest_val(const int x, const int y) const {
    if (plots[x][y] != nullptr) {
      return plots[x][y]->harvest();
    }
    return 0;
}

int Farm::row_capacity() const {
  return rows;
}

int Farm::column_capacity() const {
  return columns;
}

std::string Farm::get_symbol(const int x, const int y) const {
  if(myPlayer->getX() == x && myPlayer->getY() == y) {
    return myPlayer->getAvatar();
  } else {
    return plots[x][y]->symbol();
  }
}

int Farm::getDays() const {
  return dayCounter;
}

void Farm::plant(int row, int column, Plot *plot) {
  Plot *current_plot = plots.at(row).at(column);
  plots.at(row).at(column) = plot;
  delete current_plot;
}

void Farm::end_day() {
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < columns; j++) {
      plots.at(i).at(j)->end_day();
    }
  }
  dayCounter = 1 + dayCounter;
}

void Farm::set_soil() {
    plots[myPlayer->getX()][myPlayer->getY()] = new Soil();
    plots[myPlayer->getX()][myPlayer->getY()]->end_day();
}

void Farm::water_plot() const {
  plots[myPlayer->getX()][myPlayer->getY()]->water();
}
