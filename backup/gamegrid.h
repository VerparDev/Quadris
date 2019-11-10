#ifndef GAME_GRID_H
#define GAME_GRID_H
#include <iostream>
#include <vector>
#include <memory>
#include "cell.h"
#include "textdisplay.h"
#include "grid.h"
#include "nextblockgrid.h"

//class GraphicsDisplay;
//class Level;
class Block;
struct Coord;

class GameGrid : public Grid {
  std::unique_ptr<NextBlockGrid> nextBlockGrid;
  int blocksDropped = 0;
  bool rowDeleted = false;
  //std::vector<std::vector<Cell>> theGrid;
  //std::shared_ptr<TextDisplay> td;
  //unique_ptr<GraphicsDisplay> *gd;
  //std::unique_ptr<Level> currLevel;
  //std::unique_ptr<Block> currBlock;
 public:
  void init(int rows, int columns);
  void modifyGridAt(int col, int row, char newSymbol);
  void setPositionAt(int col, int row, Coord newPosition);
  char getGridAt(int col, int row);
  int getBlocksDropped();
  void addToDropped();
  bool getRowDeleted();
  void switchOffDeleted();
  //void notifyObserversAt(int col, int row);
  void detectRows();
  void deleteRow(int row);

  friend std::ostream& operator<<(std::ostream& out, const Grid& g);
};

#endif
