#ifndef IBLOCK_H
#define IBLOCK_H
#include "block.h"

class IBlock : public Block {
 public:
  IBlock(bool heavy=false);
};

#endif
