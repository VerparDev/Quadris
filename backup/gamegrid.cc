#include <iostream>
#include <vector>
#include <iostream>
#include "coord.h"
#include "cell.h"
#include "textdisplay.h"
#include "graphicsdisplay.h"
#include "grid.h"
#include "gamegrid.h"

using namespace std;

void GameGrid::init(int rows, int columns){

  theGrid.clear();

  //Add Cells to theGrid.
  for (int r = 0; r < rows; ++r){
    theGrid.emplace_back(vector<Cell>());
    for (int c = 0; c < columns; ++c){
      theGrid[r].emplace_back(Cell{Coord{c, r}, 0, Coord{0,0}});
    }
  }
for (int i = 0; i < rows; i++) {
  for (int j = 0; j < columns; j++) {
    cout << theGrid[i][j].getSymbol();
  }
  cout << endl;
}


  //Create the TextDisplay.
  td = make_shared<TextDisplay>(rows, columns);
  gd = make_shared<GraphicsDisplay>(100, 500, 1000);

  //Add td as an observer to each Cell on theGrid.
  for (int r = 0; r < rows; ++r){
    for (int c = 0; c < columns; ++c){
      (theGrid[r][c]).attach(td);
      (theGrid[r][c]).attach(gd);
    }
  }
}

void GameGrid::modifyGridAt(int col, int row, char newSymbol) {
  (theGrid[row][col]).setSymbol(newSymbol);
}

void GameGrid::setPositionAt(int col, int row, Coord newPosition) {
  (theGrid[row][col]).setPosition(newPosition);
}

char GameGrid::getGridAt(int col, int row) {
  return (theGrid[row][col]).getSymbol();
}

int GameGrid::getBlocksDropped() {
  return blocksDropped;
}

void GameGrid::addToDropped() {
  blocksDropped++;
}

bool GameGrid::getRowDeleted() {
  return rowDeleted;
}

void GameGrid::switchOffDeleted() {
  rowDeleted = false;
}
/*
void Grid::notifyObserversAt(int col, int row) {
  (theGrid[row][col]).notifyObservers();
}
*/
ostream& operator<<(ostream& out, const Grid& g){
  out << *(g.td);
  return out;
}

void GameGrid::detectRows() {
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
    /*for (int i = k; i < rowsToDelete.size(); ++i) {
      ++(rowsToDelete[i]);
    }*/
  }
/*
  //for each row from the bottom up, check if the row is filled
  for (int i = theGrid.size() - 1; i >= 0; --i) {
    cout << "now looking at row: " << i << endl;
    bool needtodelete = true;
    //for each column in the row, check if the columns are all non-empty
    for (int j = 0; j < theGrid[0].size(); ++j) {
      //cout << "now looking at column: " << j << ", ";
      if (theGrid[i][j].getSymbol() == ' ') {
        //cout << "found a blank space at row " << i  << ", column " << j << endl;
        needtodelete = false;
        break;
      }
    }
   //if a row is completely full, delete it
    if (needtodelete) {
      cout << "row deletion at row " << i << endl;
      deleteRow(i);
    }
  }
*/
}

/*void Grid::deleteRow(vector<int> rowsToDelete) {
  int numRowsToDelete = rowsToDelete.size();
  cout << numRowsToDelete << " rows need deletion" << endl;
  int numCol = theGrid[0].size();

  for (int row = 0; row < numRowsToDelete; ++row) {
    cout << "ERASED" << endl;
    theGrid.erase(theGrid.begin() + rowsToDelete[row]);
    for (int r = row - 1; r >= 0; --r) {
      for (int c = numCol; c >= 0; --c) {
        theGrid[r][c].down();
        //notifyObserversAt(r, c);
      }
    }
  }

  for (int row = numRowsToDelete - 1; row >= 0; --row) {
    theGrid.emplace(theGrid.begin(), vector<Cell>());
    for (int col = 0; col < numCol; ++col) {
      theGrid[0].emplace_back(Cell{Coord{col, row}});
      theGrid[0][col].attach(td);
    }
  }

  for (int j = theGrid.size() - 1; j >= 0; --j) {
    for (int k = 0; k < theGrid[0].size(); ++k) {
      cout << "now notifying " << k << ", " << j << endl;
      notifyObserversAt(k, j);
    }
  }
}*/

void GameGrid::deleteRow(int row) {
  //before deleting, notify all cells to account for dead comrades
  //(i'm leaving this out for now because there are enough things to worry about in the beginning)

  //all cells in the row to be deleted must notify their comrades that they're about to die
  //for (int i = 0; i < theGrid.size; ++i) {
  //  (theGrid[i][row]).notify(theGrid[i][row]);
  //}
  /*
  for (int i = 0;i < theGrid[row].size(); ++i) {
    cout << getGridAt(i, row);
  }
  cout << endl;
  */
  //erases the entire row
  theGrid.erase(theGrid.begin() + row);
  //after deleting, change all coordinates in the remaining cells above the deleted row to move down by 1
  for (int i = 0; i < theGrid.size(); ++i) {
    for (int j = 0; j < theGrid[0].size(); ++j) {
      //std::cout << "x:" << theGrid[i][j].getPosition().x << ",y:" << theGrid[i][j].getPosition().y <<theGrid[i][j].getSymbol();
    }
    //std::cout << std::endl;
  }

  for (int j = row - 1; j >= 0; --j) {
    for (int k = 0; k < theGrid[0].size(); ++k) {
      //cout << "(" << k << ", " << j << "): " << getGridAt(k, j) << endl;
      theGrid[j][k].down();
 //     cout << "below, at (" << k << ", " << j + 1 << "): " << getGridAt(k, j + 1) << endl;
      //setPositionAt(k, j, Coord{k, j + 1});
      //modifyGridAt(k, j, ' ');
      //notifyObserversAt(k, j);
    }
  }

  //finally, push a new row of blank cells onto the vector
  theGrid.emplace(theGrid.begin(), vector<Cell>());
  for (int l = 0; l < 11; ++l) {
    theGrid[0].emplace_back(Cell{Coord{l, 0}, textPosition, windowPosition});
    theGrid[0][l].attach(td);
  }
/*
  for (int i = 0; i < theGrid.size(); ++i) {
    for (int j = 0; j < theGrid[0].size(); ++j) {
      std::cout << "x:" << theGrid[i][j].getPosition().x << ",y:" << theGrid[i][j].getPosition().y <<theGrid[i][j].getSymbol();
    }
    std::cout << std::endl;
  }
*/
  /*for (int j = theGrid.size() - 1; j >= 0; --j) {
    for (int k = 0; k < theGrid[0].size(); ++k) {
      //cout << "now notifying " << k << ", " << j << endl;
//      notifyObserversAt(k, j);
    }
  }*/
}
