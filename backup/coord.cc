//coord.cc
#include "coord.h"
#include <iostream>

Coord Coord::operator+(Coord rhs) {
  std::cout << "ADD" << std::endl;
  return {x + rhs.x, y + rhs.y};
}

Coord Coord::operator-(Coord rhs) {
  return {x - rhs.x, y - rhs.y};
}
