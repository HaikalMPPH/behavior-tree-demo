#ifndef MOVEABLE_ACTOR_HPP
#define MOVEABLE_ACTOR_HPP

#include "engine/actor.hpp"

class MovableActor {
private:
  Actor _actor;
  float _velocity;
  Vector2 _direction;
public:
  MovableActor(Vector2 position, Color c, float velocity);
  ~MovableActor();

  void render();
  void update();

  void move_to(Vector2 target, float frame_delta);
  void move_to(float frame_delta);

  void set_dir(Vector2 dir);

  Vector2 get_position();
  void set_position(Vector2 position);
  void set_position(float x, float y);

  // will be deleted soon
  void set_color(Color c);
};

#endif
