#ifndef ANSICLEAR_H
#define ANSICLEAR_H
#include <iostream>
inline void ansi_clear() {
  std::cout << "\033[2J\033[H";
}
#endif
