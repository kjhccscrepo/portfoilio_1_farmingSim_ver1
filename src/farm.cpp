#include "../src/farm.hpp"

Farm::Farm(const int ini_rows, const int ini_columns, Player *player_ptr) {
    myPlayer = player_ptr;
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
}

int Farm::harvest_val() {
    if (plots[myPlayer->row()][myPlayer->column()] != nullptr) {
      return plots[myPlayer->row()][myPlayer->column()]->harvest();
    }
  return 0;
}

int Farm::row_capacity() const {
  return rows;
}

int Farm::column_capacity() const {
  return columns;
}

std::string Farm::get_symbol(int row, int column) const {
  if(myPlayer->row() == row && myPlayer->column() == column) {
    return myPlayer->getAvatar();
  } else {
    return plots[row][column]->symbol();
  }
}

void Farm::plant(int row, int column, Plot *plot) {
  Plot *current_plot = plots.at(row).at(column);
  plots.at(row).at(column) = plot;
  delete current_plot;
}

void Farm::end_day() const {
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < columns; j++) {
      plots.at(i).at(j)->end_day();
    }
  }
}

void Farm::set_soil() {
    plots[myPlayer->row()][myPlayer->column()] = new Soil();
}
