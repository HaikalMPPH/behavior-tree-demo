#include "engine/movable_actor.hpp"

MovableActor::MovableActor(
  Vector2 position, Color color, float velocity
) : _actor {Actor(position, color)}
  , _velocity {velocity}
  , _direction {Vector2 {0.0f, 0.0f}}
{}

MovableActor::~MovableActor() {}

void
MovableActor::move_to(Vector2 target, float frame_delta) {
  _direction = Vector2Normalize(target);

  _actor.set_position(
    _actor.get_position().x + _direction.x * _velocity * frame_delta,
    _actor.get_position().y + _direction.y * _velocity * frame_delta
  ); 
}

// if the direction is already set with set_dir()
void
MovableActor::move_to(float frame_delta) {
  _actor.set_position(
    _actor.get_position().x + _direction.x * _velocity * frame_delta,
    _actor.get_position().y + _direction.y * _velocity * frame_delta
  ); 
}

void
MovableActor::update() {
  _actor.update();
}
void
MovableActor::render() {
  _actor.render();
}

void
MovableActor::set_dir(Vector2 dir) {
  _direction = Vector2Normalize(dir);
}

Vector2 
MovableActor::get_position() { 
  return _actor.get_position();
}

void 
MovableActor::set_position(Vector2 position) { 
  _actor.set_position(position);
}
void 
MovableActor::set_position(float x, float y) { 
  _actor.set_position(x, y);
}
void
MovableActor::set_color(Color c) {
  _actor.set_color(c);
}
