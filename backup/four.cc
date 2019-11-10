//four.cc
#include "four.h"
#include "badblock.h"
#include "gamegrid.h"

Four::Four(std::string source): Level{source, 9, true, true} {
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

void Four::levelEnhancement(GameGrid &gg) {
  int badBlockInterval = 5;
  if (gg.getBlocksDropped() % badBlockInterval == 0) { //add blocksDropped and rowDeleted to Grid!!
    if (gg.getRowDeleted()) {
      gg.switchOffDeleted();
    } else {
      BadBlock bad{false};
      bad.drop(gg);
    }    
  }
}
