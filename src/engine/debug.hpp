#ifndef DEBUG_HPP
#define DEBUG_HPP

#include <raylib.h>
#include "engine/actor.hpp"

class Actor;

class Debug {
private:
  const char* _statusMessage;
  float* _statusVal;
  Actor* _refActor;
public:
  Debug(Actor* refActor);
  ~Debug();

  void ShowStatus();

  void SetStatus(const char* status, float* statusVal);
};

#endif
