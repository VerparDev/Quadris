#include <vector>
#include "iblock.h"
#include "coord.h"

IBlock::IBlock(bool heavy): Block{'I', Coord{0,6}, heavy} {
//  symbol = 'I';
  //this coord is the top tail end of the I
  coords.emplace_back(Coord{0,3});
  coords.emplace_back(Coord{0,4});
  coords.emplace_back(Coord{0,5});
  //this coord is the bottom tail end of the I
  coords.emplace_back(Coord{0,6});

//  corner = Coord{0,6};
}
