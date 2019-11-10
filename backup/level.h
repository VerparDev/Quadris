//level.h
#ifndef LEVEL_H
#define LEVEL_H

#include <memory>
#include <vector>
#include <string>
#include <fstream>

class Block;
class GameGrid;

class Level {
 protected:
  std::vector<char> probabilities;
  std::string source;
  std::fstream sourceStream;
  int seed = 0;
  int maxProbability;
  bool isHeavy;
  bool randomized;
  std::shared_ptr<Block> genRandBlock(char blockName);
 public:
  Level(std::string source, int maxProbability, bool randomized=true, bool isHeavy=false);
  virtual ~Level()=0;
  virtual void changeRandomized();
  std::shared_ptr<Block> createBlock();
  virtual void levelEnhancement(GameGrid &gg);
};

#endif
