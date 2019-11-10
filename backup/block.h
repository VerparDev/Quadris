#ifndef BLOCK_H
#define BLOCK_H
#include <vector>
#include "coord.h"

class GameGrid;

class Block {
  void moveDown(GameGrid &g);
  Coord getCorner(std::vector<Coord> newCoords);
 protected:
  char symbol;
  std::vector<Coord> coords;
  Coord corner;
  bool heavy;
 public:
  Block(char symbol, Coord corner, bool heavy=false);

  void left(GameGrid &g);
  void right(GameGrid &g);
  void down(GameGrid &g);
  void clockwise(GameGrid &g);
  void counterclockwise(GameGrid &g);
  void drop(GameGrid &g);
  void move(std::vector<Coord>, GameGrid &g);
};

#endif
