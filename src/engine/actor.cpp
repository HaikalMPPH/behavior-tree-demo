#include "actor.hpp"

Actor::Actor(Vector2 pos, Color c) 
    : position {pos} 
    , color {c} {}

Actor::~Actor() {
  cleanup();
}

void
Actor::update() {
}

void
Actor::render() {
  DrawCircleV(position, 15, color);
}

void
Actor::cleanup() {
}
