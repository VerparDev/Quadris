#include <vector>
#include "jblock.h"

JBlock::JBlock(bool heavy): Block{'J', Coord{0,5}, heavy} {
//  symbol = 'J';
  //tail end of the long part of J
  coords.emplace_back(Coord{1,3});
  //second part of the long part of J
  coords.emplace_back(Coord{1,4});
  //'corner' of the J
  coords.emplace_back(Coord{1,5});
  //tail end of the short part of J
  coords.emplace_back(Coord{0,5});
//  rotationOffset = Coord{1,1};
}
