#include <vector>
#include "zblock.h"
#include "coord.h"

ZBlock::ZBlock(bool heavy): Block{'Z', Coord{0,6}, heavy} {
//  symbol = 'I';
  //this coord is the top tail end of the I
  coords.emplace_back(Coord{0,3});
  coords.emplace_back(Coord{1,3});
  coords.emplace_back(Coord{1,4});
  //this coord is the bottom tail end of the I
  coords.emplace_back(Coord{2,4});

//  corner = Coord{0,6};
}
