//four.h
#ifndef FOUR_H
#define FOUR_H

#include "level.h"
#include <string>

class Block;

class Four: public Level {
  public:
    Four(std::string source);
    void levelEnhancement(GameGrid &gg) override;
};

#endif

