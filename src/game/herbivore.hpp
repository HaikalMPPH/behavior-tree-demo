#ifndef HERBIVORE_HPP
#define HERBIVORE_HPP

#include "engine/agent.hpp"
#include "engine/actor.hpp"

struct Game;

struct Herbivore {
  Actor actor;
  Agent agent;
  Game* game;
  float velocity;
  Vector2 direction;

  Action* move_to_direction;
  Action* idle;
  Action* set_random_directon;

  Herbivore(Game* g, Vector2 p, Color c, float tr, float v);
  ~Herbivore();

  void update();
  void ai_update();
  void render();
  void create_action();
  void create_behavior();
};

#endif
