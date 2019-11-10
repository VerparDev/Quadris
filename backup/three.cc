//three.cc
#include "three.h"
#include "level.h"
#include <cstdlib>
#include <string>

Three::Three(std::string source): Level{source, 9, true, true} {
  std::vector<char> newProbs;
  newProbs.emplace_back('S');
  newProbs.emplace_back('S');
  newProbs.emplace_back('Z');
  newProbs.emplace_back('Z');
  newProbs.emplace_back('J');
  newProbs.emplace_back('L');
  newProbs.emplace_back('I');
  newProbs.emplace_back('T');
  newProbs.emplace_back('O');
  probabilities = newProbs;
}

/*std::unique_ptr<Block> createBlock() {
  char randBlock = probabilities[srand(5) % 9];
  return genRandBlock(randBlock);
}*/

