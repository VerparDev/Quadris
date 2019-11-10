//level.cc
#include "level.h"
#include "block.h"
#include <vector>
#include <cstdlib>
//block files
#include "jblock.h"
#include "lblock.h"
#include "iblock.h"
#include "sblock.h"
#include "zblock.h"
#include "tblock.h"
#include "oblock.h"

Level::Level(std::string source, int maxProbability, bool randomized, bool isHeavy):
 source{source}, maxProbability{maxProbability}, isHeavy{isHeavy}, randomized{randomized}, sourceStream{source} {}

Level::~Level() {}

std::shared_ptr<Block> Level::genRandBlock(char blockName) {
  if (blockName == 'J') {
    return std::make_shared<JBlock>(isHeavy);
  } else if (blockName == 'L') {
    return std::make_shared<LBlock>(isHeavy);
  } else if (blockName == 'I') {
    return std::make_shared<IBlock>(isHeavy);
  } else if (blockName == 'S') {
    return std::make_shared<SBlock>(isHeavy);
  } else if (blockName == 'Z') {
    return std::make_shared<ZBlock>(isHeavy);
  } else if (blockName == 'T') {
    return std::make_shared<TBlock>(isHeavy);
  } else if (blockName == 'O') {
    return std::make_shared<OBlock>(isHeavy);
  }  
}

void Level::changeRandomized() { randomized = !randomized; }

std::shared_ptr<Block> Level::createBlock() {
  if (randomized) {
    return genRandBlock(probabilities[rand() % maxProbability]);
  } else {
    char readFrom;
    sourceStream >> readFrom;
    return genRandBlock(readFrom);
  }
}

void Level::levelEnhancement(GameGrid &gg) {}
