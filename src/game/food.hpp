#ifndef FOOD_HPP
#define FOOD_HPP

#include "engine/actor.hpp"

class Food {
private:
  Actor _actor;
public:
  Food(Vector2 position, Color color);
  ~Food();

  void render();
  Vector2 get_position() { return _actor.get_position(); }
};

#endif
