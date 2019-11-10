#include <iostream>
#include <vector>
#include <iostream>
#include "coord.h"
#include "cell.h"
#include "textdisplay.h"
#include "grid.h"

using namespace std;
/*
void Grid::init(int rows, int columns){

  //Add Cells to theGrid.
  for (int r = 0; r < rows; ++r){
    theGrid.emplace_back(vector<Cell>());
    for (int c = 0; c < columns; ++c){
      theGrid[r].emplace_back(Cell{Coord{c, r}, textPosition, windowPosition});
    }
  }

  //Create the TextDisplay.
  td = make_shared<TextDisplay>(rows, columns);

  //Add td as an observer to each Cell on theGrid.
  for (int r = 0; r < rows; ++r){
    for (int c = 0; c < columns; ++c){
      (theGrid[r][c]).attach(td);
    }
  }
}

void Grid::modifyGridAt(int col, int row, char newSymbol) {
  (theGrid[row][col]).setSymbol(newSymbol);
}
void Grid::setPositionAt(int col, int row, Coord newPosition) {
  (theGrid[row][col]).setPosition(newPosition);
}

char Grid::getGridAt(int col, int row) {
  return (theGrid[row][col]).getSymbol();
}

int Grid::getTextPosition() {
  return textPosition;
}

Coord Grid::getWindowPosition() {
  return windowPosition;
}
*/
void Grid::notifyObserversAt(int col, int row) {
  (theGrid[row][col]).notifyObservers();
}
/*
ostream& operator<<(ostream& out, const Grid& g){
  out << *(g.td);
  return out;
}

void Grid::detectRows() {
  char emptyCell = ' ';
  bool needToDelete = true;
  vector<int> rowsToDelete;

  //cout << "theGrid.size() is " << theGrid.size() << endl;
  //cout << "theGrid[0].size is " << theGrid[0].size() << endl;
  for (int r = theGrid.size() - 1; r >= 0; --r) {
    for (int c = theGrid[r].size() - 1; c >= 0; --c) {
      if (getGridAt(c, r) == emptyCell) {
        needToDelete = false;
        break;
      }
    }

    if (needToDelete) {
      //cout << "full row detected at " << r << endl;
      rowsToDelete.emplace_back(r + rowsToDelete.size());
    }
    needToDelete = true;
  }

  for (int k = 0; k < rowsToDelete.size(); ++k) {
    deleteRow(rowsToDelete[k]);
  }
}

void Grid::deleteRow(int row) {
  //before deleting, notify all cells to account for dead comrades
  //(i'm leaving this out for now because there are enough things to worry about in the beginning)

  //all cells in the row to be deleted must notify their comrades that they're about to die
  //for (int i = 0; i < theGrid.size; ++i) {
  //  (theGrid[i][row]).notify(theGrid[i][row]);
  //}
  for (int i = 0;i < theGrid[row].size(); ++i) {
    cout << getGridAt(i, row);
  }
  cout << endl;

void Grid::deleteRow(int row) {
  
  //erases the entire row
  theGrid.erase(theGrid.begin() + row);
  //after deleting, change all coordinates in the remaining cells above the deleted row to move down by 1
  for (int i = 0; i < theGrid.size(); ++i) {
    for (int j = 0; j < theGrid[0].size(); ++j) {
    }
  }

  for (int j = row - 1; j >= 0; --j) {
    for (int k = 0; k < theGrid[0].size(); ++k) {
      theGrid[j][k].down();
    }
  }

  //finally, push a new row of blank cells onto the vector
  theGrid.emplace(theGrid.begin(), vector<Cell>());
  for (int l = 0; l < 11; ++l) {
    theGrid[0].emplace_back(Cell{Coord{l, 0}});
    theGrid[0][l].attach(td);
  }
}
*/
