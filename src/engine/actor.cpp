#include "actor.hpp"

Actor::Actor(Vector2 pos, Color c) 
  : _position {pos} 
  , _color {c} {}

Actor::~Actor() {
  cleanup();
}

void
Actor::update() {
}

void
Actor::render() {
  DrawCircleV(_position, 15, _color);
}

void
Actor::cleanup() {
  // cleaning up resources
}

void
Actor::set_position(Vector2 position) {
  _position = position;
}

void
Actor::set_position(float x, float y) {
  _position.x = x;
  _position.y = y;
}
void
Actor::set_color(Color c) {
  _color = c;
}

Vector2
Actor::get_position() {
  return _position;
}
