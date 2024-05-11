#ifndef AGENT_HPP
#define AGENT_HPP

#include "ai/ai.hpp"
#include "actor.hpp"

struct Agent {
  BehaviorTreeBuilder* btb;
  BehaviorTree* bt;
  float tick_rate;

  Agent(float tick_rate);
  ~Agent();

  void cleanup();
  void update();
};

#endif
