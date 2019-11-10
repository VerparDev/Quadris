#include "info.h"
#include "cell.h"
#include "coord.h"

Cell::Cell(Coord position, int textPosition, Coord windowPosition): 
 Subject{position, textPosition, windowPosition}, Observer{info} {}
//  obsInfo = info;
//}
Cell::~Cell() {
  char emptyCells = ' ';
  setSymbol(emptyCells);
  notifyObservers();
}
//Cell::~Cell() {}

void Cell::notify(Subject& from){
  const char emptyCell = ' ';
  int numSubjects = getObservers().size();

  if (from.getSymbol() == emptyCell) {
    for (int i = 0; i < numSubjects; ++i) {
      if ((observers[i]->getObsPosition().x == from.getPosition().x) &&
          (observers[i]->getObsPosition().y == from.getPosition().y)) {
        observers.erase(observers.begin() + i);
      }
    }
  }
}

/*void Cell::setChar(char symbol){
  this->symbol = symbol;
  notifyObservers();
}

char Cell::getSymbol(){
  return getInfo().getSymbol();
}

Coord Cell::getPosition(){
  return getInfo().getPosition();
}*/

void Cell::down(){
  //setPosition(Coord{getPosition().x, getPosition().y + 1});
  ++(info->position.y);
  notifyObservers();
}
