#ifndef ANSICLEAR_H
#define ANSICLEAR_H
#include <iostream>
void ansi_clear() {
  std::cout << "\033[2J\033[H";
}
#endif
