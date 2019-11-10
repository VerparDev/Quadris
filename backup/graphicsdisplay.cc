//graphicsdisplay.cc
#include <iostream>
#include "graphicsdisplay.h"
#include "info.h"
#include "subject.h"
using namespace std;

GraphicsDisplay::GraphicsDisplay(int cellSize, int winXSize, int winYsize):
 Observer{nullptr}, cellSize{cellSize}, winXSize{winXSize}, winYSize{winYSize}, xw{winXSize, winYSize} {}
//  xw.fillRectangle(0, 0, winSize, winSize, Xwindow::Blue);

int GraphicsDisplay::getColour(char symbol) {
  switch(symbol) {
    case 'L':
      return Xwindow::Orange;
    case 'J':
      return Xwindow::Blue;
    case 'S':
      return Xwindow::Green;
    case 'Z':
      return Xwindow::Red;
    case 'T':
      return Xwindow::Purple;
    case 'O':
      return Xwindow::Yellow;
    case 'I':
      return Xwindow::Pink;
    case '*':
      return Xwindow::Brown;
    case '?':
      return Xwindow::Black;
    default:
      return Xwindow::White;
  }

/*  if(symbol == 'L') return XWindow::Blue;

  else if */
}

void GraphicsDisplay::notify(Subject &from) {
  xw.fillRectangle(from.getWindowPosition().x + from.getPosition().x * cellSize,
                   from.getWindowPosition().y + from.getPosition().y * cellSize,
                   cellSize, cellSize, getColour(from.getSymbol()));
  /*auto info = whoNotified.getInfo();
  int cellSize = winSize / gridSize;
  switch(info.colour) {
   case Colour::Black:
    xw.fillRectangle(info.col * cellSize, info.row * cellSize, cellSize, cellSize, Xwindow::Black);
    break;
   case Colour::White:
    xw.fillRectangle(info.col * cellSize, info.row * cellSize, cellSize, cellSize, Xwindow::White);
    break;
   default:
    xw.fillRectangle(info.col * cellSize, info.row * cellSize, cellSize, cellSize, Xwindow::Blue);
  }*/
}
