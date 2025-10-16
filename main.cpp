#include <iostream>

#include "src/player.hpp"
#include "src/farm.hpp"
#include "src/farm_printer.hpp"
#include "src/carrot.hpp"

int main() {
  Player player;
  Farm farm(7, 8, &player);
  FarmPrinter printer(&farm);
  std::cout << printer.pp() << std::endl;

  Carrot *carrot = new Carrot();
  farm.plant(1, 2, carrot);
  std::cout << printer.pp() << std::endl;

  player.move_right();
  player.move_right();
  player.move_right();
  player.move_down();
  std::cout << printer.pp() << std::endl;
}
