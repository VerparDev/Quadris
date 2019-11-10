#ifndef NEXT_BLOCK_GRID_H
#define NEXT_BLOCK_GRID_H
#include <memory>
#include <vector>
#include "grid.h"
#include "level.h"

class Block;

class NextBlockGrid : public Grid {
  std::string source;
  std::shared_ptr<Level> level;
  int levelAt=0;
//  std::vector<std::unique_ptr<Level>> levels;
  std::shared_ptr<Level> makeNewLevel(int level);
 public:
  std::shared_ptr<Block> getShape();
  
  void levelUp();
  void levelDown();
};

#endif
