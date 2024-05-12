#ifndef ACTOR_HPP
#define ACTOR_HPP

#include <raylib.h>
#include <raymath.h>

class Actor {
private:
  Vector2 _position;
  Color _color;
public:
  Actor(Vector2 p, Color c);
  ~Actor();

  void Update();
  void Render();
  Vector2 GetPosition();
  void SetColor(Color c);
  void SetPosition(Vector2 position);
  void SetPosition(float x, float y);

  void Cleanup();
};

#endif
