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
  float hunger;
  float hunger_decrement;
  float hunger_threshold;

  Action* move_to_direction;
  Action* idle;
  Action* set_random_directon;

  Condition* is_hungry;

  Herbivore(Game* g, Vector2 p, Color c, float tr, float v);
  ~Herbivore();

/////////////////// CORE METHODS ////////////////////////////////////// 
  void update();
  void ai_update();
  void render();

/////////////////// AI METHODS //////////////////////////////////////// 
  void create_action();
  void create_condition();
  void create_behavior();

/////////////////// LOGIC METHODS ///////////////////////////////////// 
  void wrap_around();
  void diminish_hunger();
};

#endif
