#include "actor.hpp"

Actor::Actor(Vector2 pos, Color c) 
  : _position {pos} 
  , _color {c} {}

Actor::~Actor() {
  Cleanup();
}

void
Actor::Update() {
}

void
Actor::Render() {
  DrawCircleV(_position, 15, _color);
}

void
Actor::Cleanup() {
  // cleaning up resources
}

void
Actor::SetPosition(Vector2 position) {
  _position = position;
}

void
Actor::SetPosition(float x, float y) {
  _position.x = x;
  _position.y = y;
}
void
Actor::SetColor(Color c) {
  _color = c;
}

Vector2
Actor::GetPosition() {
  return _position;
}
