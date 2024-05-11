#include "game/food.hpp"

Food::Food(Vector2 p, Color c) 
  : _actor {Actor(p, c)}
{}

Food::~Food() {
  
}

void
Food::render() {
  _actor.render();
}
