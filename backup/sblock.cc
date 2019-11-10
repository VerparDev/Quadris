#include <vector>
#include "sblock.h"
#include "coord.h"

SBlock::SBlock(bool heavy): Block{'S', Coord{0,5}, heavy}/*: Block{'L', std::vector<Coord> = [Coord{0,3}, Coord{0,4}, Coord{0,5}, Coord{1,5}], Coord{1,1}*/ {
//  symbol = 'S';
  //this coord is the tail end of the long part of the L
  coords.emplace_back(Coord{0,3});
  //this coord is the middle end of the long part of the L
  coords.emplace_back(Coord{0,4});
  //this coord is the corner cell of the L
  coords.emplace_back(Coord{1,4});
  //this coord is the short tail end of the L
  coords.emplace_back(Coord{1,5});
//  corner = Coord{0,5};

}
