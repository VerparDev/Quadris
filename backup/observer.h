#ifndef OBSERVER_H
#define OBSERVER_H

#include <memory>

class Subject;
struct Info;
struct Coord;

class Observer {
 protected:
  std::shared_ptr<Info> obsInfo;
 public:
  Observer(std::shared_ptr<Info> obsInfo);
  virtual ~Observer() = default; //Needed?

  Coord getObsPosition();
  /*void setObsPosition(Coord newPosition);*/
  virtual void notify(Subject& from)=0;
};

#endif
