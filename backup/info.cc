#include "coord.h"
#include "info.h"

Info::Info(char symbol, Coord position, int textPosition, Coord windowPosition): 
 symbol{symbol}, position{position} {}
/*
char Info::getSymbol() {
  return symbol;
}

void Info::setSymbol(char newSymbol) {
  symbol = newSymbol;
}

Coord Info::getPosition() {
  return position;
}

void Info::setPosition(Coord newPosition) {
  position.x = newPosition.x;
  position.y = newPosition.y; 
}
*/
