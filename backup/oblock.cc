#include <vector>
#include "oblock.h"
#include "coord.h"

OBlock::OBlock(bool heavy): Block{'O', Coord{0,4}, heavy} {
//  symbol = 'I';
  //this coord is the top tail end of the I
  coords.emplace_back(Coord{0,3});
  coords.emplace_back(Coord{0,4});
  coords.emplace_back(Coord{1,3});
  //this coord is the bottom tail end of the I
  coords.emplace_back(Coord{1,4});

//  corner = Coord{0,6};
}
