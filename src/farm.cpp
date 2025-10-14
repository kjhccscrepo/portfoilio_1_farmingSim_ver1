#include <string>

#include "farm.hpp"

Farm::Farm(int rows, int columns) : rows(rows), columns(columns) {}

int Farm::number_of_rows() {
  return rows;
}

int Farm::number_of_columns() {
  return columns;
}
