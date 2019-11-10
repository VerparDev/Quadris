#include <vector>
#include <memory>
#include "coord.h"
#include "info.h"
#include "subject.h"
#include "observer.h"
using namespace std;

Subject::Subject (Coord position, int textPosition, Coord windowPosition): 
 info{make_shared<Info>(' ', position, textPosition, windowPosition)} {}
Subject::~Subject (){}

char Subject::getSymbol() {
  return info->symbol;
}
Coord Subject::getPosition() {
  return info->position;
}

int Subject::getTextPosition() {
  return info->textPosition;
}

Coord Subject::getWindowPosition() {
  return info->windowPosition;
}

std::vector<std::shared_ptr<Observer>> Subject::getObservers() {
  return observers;
}

void Subject::setSymbol(char newSymbol) {
  info->symbol = newSymbol;
}
void Subject::setPosition(Coord newPosition) {
  info->position = newPosition;
}
void Subject::setObservers(std::vector<std::shared_ptr<Observer>> newObservers) {
  observers = newObservers;
}

void Subject::attach(shared_ptr<Observer> o){
  observers.emplace_back(o);
}
void Subject::detach(shared_ptr<Observer> o){
  for (auto it = observers.begin(); it != observers.end(); ++it) {
    if (*it == o) {
      observers.erase(it);
      break;
    }
  }
}
void Subject::notifyObservers () {
  for (auto &obs : observers) obs->notify(*this);
}
