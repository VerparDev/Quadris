#include <vector>
#include "tblock.h"
#include "coord.h"

TBlock::TBlock(bool heavy): Block{'T', Coord{0,4}, heavy} {
//  symbol = 'I';
  //this coord is the top tail end of the I
  coords.emplace_back(Coord{0,3});
  coords.emplace_back(Coord{1,3});
  coords.emplace_back(Coord{2,3});
  //this coord is the bottom tail end of the I
  coords.emplace_back(Coord{2,4});

//  corner = Coord{0,6};
}
