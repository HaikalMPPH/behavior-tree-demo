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

  void Render();
  void Update();

  void MoveTo(Vector2 target, float frameDelta);
  void MoveTo(float frameDelta);

  void SetDir(Vector2 dir);

  Vector2 GetPosition();
  void SetPosition(Vector2 position);
  void SetPosition(float x, float y);

  // will be deleted soon
  void SetColor(Color c);

  Actor* GetActor();
};

#endif
