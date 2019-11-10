#include <iostream>
#include <vector>
#include <stdexcept>
#include "coord.h"
#include "block.h"
#include "gamegrid.h"
//#include "grid.h"
using namespace std;

Block::Block(char symbol, Coord corner, bool heavy):
  symbol{symbol}, coords{coords}, corner{corner}, heavy{heavy} {}

void Block::left(GameGrid &g) {
  vector<Coord> newCoords;
  
  for (auto &crd : coords) {
    newCoords.push_back(Coord{crd.x - 1, crd.y});
  }

  try {
    move(newCoords, g);
  } catch (...) { return; }
  corner.x--;  
  coords = newCoords;
}

void Block::right(GameGrid &g) {
  vector<Coord> newCoords;

  for (auto &crd : coords) {
    newCoords.push_back(Coord{crd.x + 1, crd.y});
  }

  try {
    move(newCoords, g);
  } catch (...) { return; }
  corner.x++;
  coords = newCoords;
}

////////////
void Block::down(GameGrid &g) {
  try { moveDown(g);  } catch(...) { return; }
}

////////////////////////////////////////////////
void Block::moveDown(GameGrid &g) {
  vector<Coord> newCoords;
//  int numCoords = coords.size();
  for (auto &crd : coords/*int i = 0; i < numCoords; ++i*/) {
    newCoords.push_back(Coord{crd.x, crd.y + 1});
  }
  try {
    move(newCoords, g);
  } catch (...) { throw; }
  corner.y++;
  coords = newCoords;
}

Coord Block::getCorner(std::vector<Coord> newCoords) {
  int x = newCoords[0].x;
  int y = newCoords[0].y;
  for(int i = 1; i < newCoords.size(); ++i) {
    if (newCoords[i].x < x) x = newCoords[i].x;
    if (newCoords[i].y > y) y = newCoords[i].y;
  }
  return {x, y};
}
//////////////////////////////////////////

void Block::counterclockwise(GameGrid &g) {
  std::vector<Coord> newCoords;
  for (int i = 0; i < coords.size(); ++i) {
    newCoords.emplace_back(Coord{coords[i].y, coords[i].x * -1});
//    newCoords[i].x = coords[i].y;
  //  newCoords[i].y = temp * -1;
  }
  Coord newCorner = getCorner(newCoords);
  Coord distance = corner - newCorner;

  std::cout << "NEW CORNER: " << "(" << newCorner.x << "," << newCorner.y << ")" << std::endl;

  for (int i = 0; i < newCoords.size(); ++i) {
    cout << newCoords[i].x << ',' << newCoords[i].y<< std::endl;
    newCoords[i] = newCoords[i] + distance;
    cout << newCoords[i].x << ',' << newCoords[i].y<< std::endl;
  }

  for (int i = 0; i < newCoords.size(); ++i) {
    std::cout << "(" << newCoords[i].x << "," << newCoords[i].y << ")" << std::endl;
  }

  try {
    move(newCoords, g);
  } catch (...) {return; }
  coords = newCoords;
}

void Block::clockwise(GameGrid &g) {
  for (int i = 0; i < 3; ++i) {
    counterclockwise(g);
  }
};

void Block::drop(GameGrid &g) {
  //this while loop will keep running until block hits either:
  //1. the floor at y = 18
  //2. an occupied cell directly below it
  int numCoords = coords.size();
  while(true){
    try { moveDown(g); } catch(...) { break; }
  }
  //write into the grid
  for (int i = 0; i < numCoords; ++i) {
	//Need to add this setPositionAdd() function to grid
    g.setPositionAt(coords[i].x, coords[i].y, coords[i]);
//    g.modifyGridAt(coords[i].x, coords[i].y, symbol); //Don't need to do this since down already did it    
  }
}

void Block::move(vector<Coord> newCoords, GameGrid &g) {
  const char emptyCell = ' ';
  int numCoords = newCoords.size();
  int x, y;
  
  //empty current cells so it does not mistake itself for something on the grid
  for (int i = 0; i < numCoords; ++i) {
    g.modifyGridAt(coords[i].x, coords[i].y, emptyCell);
    g.notifyObserversAt(coords[i].x, coords[i].y);
  }
  //Checks if all new coords are in range and not already occupied; if not, throws an exception
  for (int i = 0; i < numCoords; ++i) {
    x = newCoords[i].x;
    y = newCoords[i].y;
    if ((x < 0 || x >= 11 || y < 0 || y >= 18 || g.getGridAt(x, y) != emptyCell)) {
      //If we can't move the block, reset it to its original position.
      for (int i = 0; i < numCoords; ++i) {
        g.modifyGridAt(coords[i].x, coords[i].y, symbol);
        g.notifyObserversAt(coords[i].x, coords[i].y);
      }
      throw range_error("Invalid Move!"); //CHANGE THE EXCEPTION.
    }
  }

  //Sets the current cells to empty cell.
  for (int i = 0; i < numCoords; ++i) {
    g.modifyGridAt(coords[i].x, coords[i].y, emptyCell);
    g.notifyObserversAt(coords[i].x, coords[i].y);
  }

  //Sets the cells at the newCoords to symbol. This is done in a different loop as there may be cases where a Coord in
  //  newCoords and coords overlaps.
  for (int i = 0; i < numCoords; ++i) {
    g.modifyGridAt(newCoords[i].x, newCoords[i].y, symbol);
    g.notifyObserversAt(newCoords[i].x, newCoords[i].y);
  }
}
