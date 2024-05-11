#ifndef ACTOR_HPP
#define ACTOR_HPP

#include <raylib.h>


class Game;

class AActor {
protected:
  Vector2 _position;
  Color _color;
  Game* _game;

public:
  AActor(Game* game);
  virtual ~AActor();

  virtual void update() = 0;
  virtual void render() = 0;

  // Optional abstract method for cleaning up actor resources.
  virtual void cleanup() {};

private:
  // Init outside of contructor
  virtual void init() {};
};

#endif
