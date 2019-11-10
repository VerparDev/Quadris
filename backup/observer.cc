#include <memory>
#include "info.h"
#include "observer.h"
#include "coord.h"
using namespace std;

Observer::Observer(std::shared_ptr<Info> obsInfo): obsInfo{obsInfo} {}

Coord Observer::getObsPosition() {
  return obsInfo->position;
}
/*
void Observer::setObsPosition(Coord newPosition) {
  obsInfo->position = newPosition;
}*/
