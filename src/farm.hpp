#pragma once

#include <string>

class Farm {
  private:
    int rows;
    int columns;

  public:
    Farm(int rows, int columns);
    int number_of_rows();
    int number_of_columns();
};
