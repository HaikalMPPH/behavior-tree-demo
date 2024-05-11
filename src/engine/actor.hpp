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

  void update();
  void render();
  Vector2 get_position();
  void set_color(Color c);
  void set_position(Vector2 position);
  void set_position(float x, float y);

  void cleanup();
};

#endif
