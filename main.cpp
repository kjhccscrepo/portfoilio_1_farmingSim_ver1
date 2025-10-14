#include <iostream>

#include "src/farm.hpp"

int main() {
  Farm farm(10, 10);
  std::cout << farm.number_of_rows() << std::endl;
}
