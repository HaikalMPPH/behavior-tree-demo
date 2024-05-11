#ifndef HERBIVORE_HPP
#define HERBIVORE_HPP

#include "engine/agent.hpp"
#include "engine/movable_actor.hpp"

class Game;

class Herbivore {
private:
  MovableActor _mov_actor;
  Agent _agent;
  Game* _game;

  float _hunger;
  float _hunger_decrement;
  float _hunger_threshold;

  // These are deleted by the behavior tree dealloc_child() method.
  Action* _move_to_direction;
  Action* _idle;
  Action* _set_random_directon;
  Action* _get_food_direction;
  Action* _move_and_eat;

  Condition* _is_hungry;

public:
  Herbivore(Game* g, Vector2 p, Color c, uint8_t tr, float v);
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
