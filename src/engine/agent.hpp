#ifndef AGENT_HPP
#define AGENT_HPP

#include "ai/ai.hpp"
#include "actor.hpp"
#include "std_includes.hpp"

class Agent {
private:
  BehaviorTreeBuilder* _btb;
  BehaviorTree* _bt;
  uint8_t _tick_rate;
public:
  Agent(uint8_t tick_rate);
  ~Agent();

  void cleanup();
  void update();

  BehaviorTreeBuilder* get_btb();
  void set_btb(BehaviorTreeBuilder* btb);
  void create_bt();

  uint8_t get_tick_rate();
};

#endif
