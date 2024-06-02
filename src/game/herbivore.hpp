#ifndef HERBIVORE_HPP
#define HERBIVORE_HPP

#include "engine/agent.hpp"
#include "engine/movable_actor.hpp"
#include "engine/debug.hpp"

class Game;

class Herbivore {
private:
  MovableActor _movActor;
  Agent _agent;
  Game* _game;
  Debug _debug;

  float _ms;
  float _msLimit;
  float _hunger;
  float _hungerDecrement;
  float _hungerThreshold;

  // These are deleted by the behavior tree dealloc_child() method.
  Action* _moveToDirection;
  Action* _idle;
  Action* _setRandomDirection;
  Action* _getFoodDirection;
  Action* _moveAndEat;

  Condition* _isHungry;

public:
  Herbivore(Game* g, Vector2 p, Color c, uint8_t tr, float v);
  ~Herbivore();

/////////////////// CORE METHODS ////////////////////////////////////// 
  void Update();
  void AiUpdate();
  void Render();

/////////////////// AI METHODS //////////////////////////////////////// 
  void CreateAction();
  void CreateCondition();
  void CreateBehavior();

/////////////////// UPDATE METHODS //////////////////////////////////// 
  void WrapAround();
  void DiminishHunger();
  void ResetMs();
};

#endif
