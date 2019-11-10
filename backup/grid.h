#ifndef GRID_H
#define GRID_H
#include <iostream>
#include <vector>
#include <memory>
#include "cell.h"
#include "textdisplay.h"
#include "coord.h"

//class GraphicsDisplay;
//class level;
class Block;
class GraphicsDisplay;
struct Coord;
class Level;

class Grid {
 protected:
  std::vector<std::vector<Cell>> theGrid;
//  std::shared_ptr<TextDisplay> td;
  //unique_ptr<GraphicsDisplay> *gd;

  std::shared_ptr<GraphicsDisplay> gd;
  //std::unique_ptr<Level> currLevel;
  std::shared_ptr<Block> currBlock;
  int textPosition;
  Coord windowPosition;
 public:
  std::shared_ptr<TextDisplay> td;
  virtual void init(int rows, int columns)=0;
  //int getTextPosition();
  //Coord getWindowPosition();
  //void modifyGridAt(int col, int row, char newSymbol);
  //void setPositionAt(int col, int row, Coord newPosition);
  //char getGridAt(int col, int row);
  void notifyObserversAt(int col, int row);
  //void detectRows();
  //void deleteRow(int row);

  friend std::ostream& operator<<(std::ostream& out, const Grid& g);
  //friend std::ostream& operator<<(std::ostream& out, const Grid& g);
};

#endif
