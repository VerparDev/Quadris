#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include <iostream>
#include <vector>
#include "observer.h"


class TextDisplay: public Observer {
  std::vector<std::vector<char>> theDisplay;
  const int rows, columns;

 public:
  TextDisplay(int rows, int columns);

  void notify(Subject &from) override;

  friend std::ostream& operator<<(std::ostream& out, const TextDisplay& td);
};

#endif
