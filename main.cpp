#include <iostream>

#include "src/farm.hpp"
#include "src/farm_printer.hpp"
#include "src/carrot.hpp"

int main() {
  Farm farm(7, 8);
  FarmPrinter printer(&farm);
  std::cout << printer.pp() << std::endl;

  Carrot *carrot = new Carrot();
  farm.plant(1, 2, carrot);
  std::cout << printer.pp();
}
