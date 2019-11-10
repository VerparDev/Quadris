#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include <memory>

struct Coord;
class Observer;
struct Info;

class Subject {
 protected:
  std::vector<std::shared_ptr<Observer>> observers;
  //std::unique_ptr<Info> info; //using pimpl idiom
  std::shared_ptr<Info> info;
 public:
//Constructors and destructors
  virtual ~Subject()=0;
  Subject(Coord position, int textPosition, Coord windowPosition);
 	
  char getSymbol();
  Coord getPosition();
  int getTextPosition();
  Coord getWindowPosition();
  std::vector<std::shared_ptr<Observer>> getObservers();


  void setSymbol(char newSymbol);
  void setPosition(Coord newPosition);
  void setObservers(std::vector<std::shared_ptr<Observer>> newObservers);

  void attach(std::shared_ptr<Observer> o);
  void detach(std::shared_ptr<Observer> o);
  void notifyObservers();
};

#endif

