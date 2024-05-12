#include "engine/agent.hpp"
#include "game/game.hpp"
#include <raymath.h>

Agent::Agent(uint8_t tickRate) 
    : _btb {nullptr} 
    , _bt {nullptr}
    , _tickRate {tickRate} 
{}

Agent::~Agent() {
  Cleanup();
}

void
Agent::Update() {
  if (_bt != nullptr) {
    _bt->BTUpdate(_tickRate);
  }
}

void
Agent::Cleanup() {
  if (_btb != nullptr && _bt != nullptr) {
    delete _bt;
    delete _btb;
    _bt = nullptr;
    _btb = nullptr;
  }
}

BehaviorTreeBuilder* 
Agent::GetBTB() {
  return _btb;
}

void 
Agent::SetBTB(BehaviorTreeBuilder* btb) {
  _btb = btb;
}

void 
Agent::CreateBT() {
  _bt = _btb->CreateTree();
}

uint8_t
Agent::GetTickRate() {
  return _tickRate;
}
