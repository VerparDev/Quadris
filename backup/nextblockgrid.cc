#include <memory>
#include "block.h"
#include "level.h"
#include "nextblockgrid.h"
//level files
#include "zero.h"
#include "one.h"
#include "two.h"
#include "three.h"
#include "four.h"

using namespace std;

std::shared_ptr<Level> NextBlockGrid::makeNewLevel(int level) {
  if (level == 0) {
    return std::make_shared<Zero>(source);
  } else if (level == 1) {
    return std::make_shared<One>(source);
  } else if (level == 2) {
    return std::make_shared<Two>(source);
  } else if (level == 3) {
    return std::make_shared<Three>(source);
  } else {
    return std::make_shared<Four>(source);
  }
}


shared_ptr<Block> NextBlockGrid::getShape() {
//  shared_ptr<Block> curr = currBlock;
//  currBlock = levels[levelAt]->createBlock();
  return currBlock;
}

void NextBlockGrid::levelUp() {
  if (levelAt == 4) return;
  ++levelAt;
  level = makeNewLevel(levelAt);
}

void NextBlockGrid::levelDown() {
  if (levelAt == 0) return;
  --levelAt;
  level = makeNewLevel(levelAt);
}
