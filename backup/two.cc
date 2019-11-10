//two.cc
#include "two.h"
#include "level.h"
#include <cstdlib>

Two::Two(std::string source): Level{source, 7} {
  std::vector<char> newProbs;
  newProbs.emplace_back('S');
  newProbs.emplace_back('Z');
  newProbs.emplace_back('J');
  newProbs.emplace_back('L');
  newProbs.emplace_back('I');
  newProbs.emplace_back('T');
  newProbs.emplace_back('O');
  probabilities = newProbs;
}
