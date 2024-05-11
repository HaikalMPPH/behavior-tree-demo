#ifndef AGENT_HPP
#define AGENT_HPP

#include "ai/ai.hpp"
#include "../engine/actor.hpp"

class Game;

class Agent : public AActor {
private:
  BehaviorTreeBuilder* _btb;
  BehaviorTree* _bt;
  float _tick_rate;

///////////////////// VARS FOR BEAHVIORS //////////////////////////////
  Vector2 _target_pos;
  Vector2 _move_direction;
  float _velocity;
///////////////////////////////////////////////////////////////////////
public:
  Agent(Game* game, float tick_rate);
  ~Agent();

  void update() override;
  void render() override;
  void cleanup() override;
  void bt_update();
private:
  void init() override;
///////////////////// CUSTOM BEHAVIOR /////////////////////////////////
private:
  Action* a_move_to_dir;
  Action* a_set_random_dir;
  Action* a_idle;
///////////////////////////////////////////////////////////////////////
};

#endif
