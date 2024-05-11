#ifndef ACTOR_HPP
#define ACTOR_HPP

#include <raylib.h>
#include <raymath.h>

struct Actor {
  Vector2 position;
  Color color;
  
  Actor(Vector2 p, Color c);
  ~Actor();

  void update();
  void render();

  void cleanup();
};

#endif
