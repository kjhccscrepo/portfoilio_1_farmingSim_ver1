#include "soil.hpp"

std::string Soil::symbol() {
  return ".";
}

void Soil::end_day() {
  // no-op
}

int Soil::harvest() {
  return 1;
}
