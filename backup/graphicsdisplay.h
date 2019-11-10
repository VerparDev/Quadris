//graphicsdisplay.cc
#ifndef GRAPHICS_DISPLAY_H
#define GRAPHICS_DISPLAY_H
#include <iostream>
#include <vector>
#include "observer.h"
#include "window.h"

class Cell;

class GraphicsDisplay: public Observer {
  const int cellSize, winXSize, winYSize;
  Xwindow xw;
  int getColour(char symbol);
 public:
  GraphicsDisplay(int cellSize, int winXSize, int winYSize);

  void notify(Subject &whoNotified) override;
};
#endif
