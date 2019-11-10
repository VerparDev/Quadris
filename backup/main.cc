#include <iostream>
#include <string>
#include "gamegrid.h"
#include "block.h"
#include "lblock.h"
#include "iblock.h"
#include "sblock.h"
using namespace std;
int main(int arc, char* argv[]) {
  //cin.exceptions(ios::eofbit|ios::failbit);
cout << "started" << endl;
  string cmd = "", inputCmd = "";
  GameGrid g;
cout << "gmeGrid made" << endl;
//  Block shape = IBlock(false);
cout << "hello" << endl;
  int numTimes = 1, possibleCmds = 0;
  bool found = false;
  
/*  try {
    while(true){
      cin >> cmd;
      if (cmd == "new") {
        g.init(18, 15);
      } else if (cmd == "right") {
        shape.right(g);
      }
    cout << g;
    }
  } catch (...) { } */
  //forego movement checking altogether just for the basic build
cout << "before" << endl;
  vector<string> cmds{"new", "left", "right", "down", "drop", "clockwise", "counterclockwise", "s"};
cout << "After" << endl;
  while (true) {

    cin >> cmd;
/*
    if (cmd == "new") {
//      g = GameGrid{};
      g.init(18, 11);
    }
    else if (cmd == "r") {
//      shape.right(g);
      //g.detectRows();
    }
    else if (cmd == "l") {
//      shape.left(g);
      //g.detectRows();
    }
    else if (cmd == "down") {
//      shape.down(g);
      //g.detectRows();
    }
    else if (cmd == "drop") {
//      shape.drop(g);
      g.detectRows();
//      shape = IBlock();
    }
    else if (cmd == "dropl") {
//     shape.drop(g);
     g.detectRows();
//     shape = LBlock();
    //cout << "CALLED" << endl;
    if (!(cin >> numTimes)) {
      cin.clear();
      //cin.ignore();
      numTimes = 1;
    }
    //cout << "Num Times" << endl;
    // if fails set to 1;
    cin >> inputCmd; 
    //cout << inputCmd << endl;
*/
    for (int i = 0; i < cmds.size(); ++i) {
      if (cmds[i] == inputCmd){
        found = true;
        ++possibleCmds;
        cmd = inputCmd;
        break;
      }
    }
    if (!found) {
      for (int i = 0; i < cmds.size(); ++i) {
        if (cmds[i].length() >= inputCmd.length()) {
          //cout << cmds[i].substr(0, inputCmd.length()) << endl;
          if (cmds[i].substr(0, inputCmd.length()) == inputCmd) {
            cmd = cmds[i];
            ++possibleCmds;
          }
        }
      }
    }
    while (numTimes > 0) {
      if (possibleCmds != 1) {
        break;
      } 
      else if (cmd == "new") {
        g.init(18, 11);
      }
      else if (cmd == "right") {
//        shape.right(g);
      }
      else if (cmd == "left") {
//        shape.left(g);
      }
      else if (cmd == "down") {
//        shape.down(g);
      }
      else if (cmd == "drop") {
//        shape.drop(g);
        g.detectRows();
//        shape = IBlock();
      }
      else if (cmd == "dropl") {
//       shape.drop(g);
       g.detectRows();
//       shape = LBlock();
      }
      else if (cmd == "drops") {
       shape.drop(g);
       g.detectRows();
       shape = SBlock();
      }
      else if (cmd == "counterclockwise") {
        shape.counterclockwise(g);
      }
      else if (cmd == "clockwise") {
        shape.clockwise(g);
      }
      else if (cmd == "s") {
        shape = SBlock();
      }
      else {
        cerr << "invalid command" << endl;
      }
      cout << g;
      --numTimes;
    }
    cmd = "";
    possibleCmds = 0;
    numTimes = 1;
    found = false;
    }
  }
}
