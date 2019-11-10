//zero.h
#ifndef ZERO_H
#define ZERO_H

#include "level.h"
#include <string>
#include <memory>

class Zero: public Level {
 public:
  Zero(std::string source);
  void changeRandomized() override;
};

#endif
