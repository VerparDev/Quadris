#ifndef COORD_H
#define COORD_H

struct Coord {
  int x, y;
 public:
  Coord operator+(Coord rhs);
  Coord operator-(Coord rhs);
};

#endif
