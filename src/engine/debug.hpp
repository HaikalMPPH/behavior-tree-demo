#ifndef DEBUG_HPP
#define DEBUG_HPP

#include <raylib.h>
#include "engine/movable_actor.hpp"

class MovableActor;

class Debug {
private:
  const char* _statusMessage;
  float* _statusVal;
  MovableActor* _refMovActor;
public:
  Debug(MovableActor* refMovActor);
  ~Debug();

  void ShowStatus();

  void SetStatus(const char* status, float* statusVal);
};

#endif
