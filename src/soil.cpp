#include "soil.hpp"
std::string Soil::symbol() {
  return ".";
}

std::string Soil::myName() {
  return "soil";
}

void Soil::end_day() {
  // no-op
}

int Soil::harvest() {
  return 1;
}
