#ifndef AGENT_HPP
#define AGENT_HPP

#include "ai/ai.hpp"
#include "actor.hpp"
#include "std_includes.hpp"

class Agent {
private:
  BehaviorTreeBuilder* _btb;
  BehaviorTree* _bt;
  uint8_t _tickRate;
public:
  Agent(uint8_t tickRate);
  ~Agent();

  void Cleanup();
  void Update();

  BehaviorTreeBuilder* GetBTB();
  void SetBTB(BehaviorTreeBuilder* btb);
  void CreateBT();

  uint8_t GetTickRate();
};

#endif
