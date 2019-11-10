#include <iostream>
#include <vector>
#include "observer.h"
#include "coord.h"
#include "textdisplay.h"
#include "subject.h"

TextDisplay::TextDisplay(int rows, int columns): Observer{nullptr}, rows{rows}, columns{columns} {
  const char emptyCell = ' ';
  std::vector<char> temp;

  for (int r = 0; r < rows; ++r) {
//   theDisplay.emplace_back(std::vector<char>);
    for (int c = 0; c < columns; ++c) {
      temp.push_back(emptyCell);
//      theDisplay[r].push_back(emptyCell);
    }
    theDisplay.push_back(temp);
    temp.clear();
  }
}

void TextDisplay::notify(Subject &from) {
  //std::cout << "(" << from.getPosition().x << "," << from.getPosition().y << ") : " << from.getSymbol() << std::endl;
  theDisplay[from.getPosition().y][from.getPosition().x] = from.getSymbol();
}

std::ostream& operator<<(std::ostream& out, const TextDisplay& td){
  int rows = td.rows;
  int column = td.columns;

  for (int r = 0; r < rows; ++r) {
    for (int c = 0; c < column; ++c) {
      out << (td.theDisplay)[r][c];
    }
    out << '\n';
  }

  return out;
}
