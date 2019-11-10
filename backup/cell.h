#ifndef _CELL_H_
#define _CELL_H_
#include "subject.h"
#include "observer.h"

struct Coord;

class Cell: public Subject, public Observer{
/*char symbol = " ";
Coord position;
Vector<shared_ptr<Subject>> subjects;*/
 public:
  //Constructors and Destructors
  Cell(Coord position, int textPosition, Coord windowPosition);
  ~Cell();

  void notify(Subject&) override;
/*  void setChar(char symbol); //Changes the symbol, updating the type of block the Cell represents. 
                                  //Notifies observers that the cell was updated.
  char getSymbol();
  Coord getPosition();*/
  void down(); //Increments the y field, moving the Cell 'down' by one. Notifies observers that the cell was moved.
};
#endif
