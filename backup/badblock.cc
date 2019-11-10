//badblock.cc

#include "badblock.h"

BadBlock::BadBlock(bool heavy): Block{'*', Coord{5,3}, heavy} {
//  symbol = '*';
  coords.emplace_back(Coord{5, 3});
//  corner = Coord{length/2, 3};
}
