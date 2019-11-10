#ifndef INFO_H
#define INFO_H
#include "coord.h"

struct Info {
  char symbol;
  Coord position;
  int textPosition;
  Coord windowPosition;
 public:
  Info(char symbol, Coord position, int textPosition, Coord windowPosition);
  /*char getSymbol();
  void setSymbol(char newSymbol);
  Coord getPosition();
  void setPosition(Coord newPosition);*/
};

#endif
