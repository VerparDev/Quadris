//zero.cc
#include "zero.h"
#include "level.h"
#include <string>
#include <fstream>

//#include "block.h"
#include "jblock.h"
#include "lblock.h"
#include "iblock.h"
#include "sblock.h"
//#include "zblock.h"
//#include "tblock.h"
//#include "oblock.h"

Zero::Zero(std::string source): Level{source, 0, false} {}

void Zero::changeRandomized() {}

/*if (createdBlock == 'J') {
    return make_unique<Block>(JBlock());
  } else if (createdBlock == 'L') {
    return make_unique<Block>(LBlock());
  } else if (createdBlock == 'I') {
    return make_unique<Block>(IBlock());
  } else if (createdBlock == 'S') {
    return make_unique<Block>(SBlock());
  } else if (createdBlock == 'Z') {
    return make_unique<Block>(ZBlock());
  } else if (createdBlock == 'T') {
    return make_unique<Block>(TBlock());
  } else if (createdBlock == 'O') {
    return make_unique<Block>(OBlock());
  }
*/
