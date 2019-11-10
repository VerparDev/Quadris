#ifndef BAD_BLOCK_H
#define BAD_BLOCK_H
#include "block.h"

class BadBlock: public Block {
 public:
  BadBlock(bool heavy);
};

#endif

