#include "engine/movable_actor.hpp"

MovableActor::MovableActor(
  Vector2 position, Color color, float velocity
) : _actor {Actor(position, color)}
  , _velocity {velocity}
  , _direction {Vector2 {0.0f, 0.0f}}
{}

MovableActor::~MovableActor() {}

void
MovableActor::MoveTo(Vector2 target, float frameDelta) {
  _direction = Vector2Normalize(target);

  _actor.SetPosition(
    _actor.GetPosition().x + _direction.x * _velocity * frameDelta,
    _actor.GetPosition().y + _direction.y * _velocity * frameDelta
  ); 
}

// if the direction is already set with SetDir()
void
MovableActor::MoveTo(float frameDelta) {
  _actor.SetPosition(
    _actor.GetPosition().x + _direction.x * _velocity * frameDelta,
    _actor.GetPosition().y + _direction.y * _velocity * frameDelta
  ); 
}

void
MovableActor::Update() {
  _actor.Update();
}
void
MovableActor::Render() {
  _actor.Render();
}

void
MovableActor::SetDir(Vector2 dir) {
  _direction = Vector2Normalize(dir);
}

Vector2 
MovableActor::GetPosition() { 
  return _actor.GetPosition();
}

void 
MovableActor::SetPosition(Vector2 position) { 
  _actor.SetPosition(position);
}
void 
MovableActor::SetPosition(float x, float y) { 
  _actor.SetPosition(x, y);
}
void
MovableActor::SetColor(Color c) {
  _actor.SetColor(c);
}

Actor*
MovableActor::GetActor() {
  return &_actor;
}
