#ifndef FOOD_HPP
#define FOOD_HPP

#include "engine/actor.hpp"

class Food {
private:
  Actor _actor;
public:
  Food(Vector2 position, Color color);
  ~Food();

  void Render();
  Vector2 GetPosition() { return _actor.GetPosition(); }
};

#endif
