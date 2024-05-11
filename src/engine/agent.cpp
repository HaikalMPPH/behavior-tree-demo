#include "engine/agent.hpp"
#include "game/game.hpp"
#include <raymath.h>

Agent::Agent(uint8_t tick_rate) 
    : _btb {nullptr} 
    , _bt {nullptr}
    , _tick_rate {tick_rate} 
{}

Agent::~Agent() {
  cleanup();
}

void
Agent::update() {
  if (_bt != nullptr) {
    _bt->bt_update(_tick_rate);
  }
}

void
Agent::cleanup() {
  if (_btb != nullptr && _bt != nullptr) {
    delete _bt;
    delete _btb;
    _bt = nullptr;
    _btb = nullptr;
  }
}

BehaviorTreeBuilder* 
Agent::get_btb() {
  return _btb;
}

void 
Agent::set_btb(BehaviorTreeBuilder* btb) {
  _btb = btb;
}

void 
Agent::create_bt() {
  _bt = _btb->create_tree();
}

uint8_t
Agent::get_tick_rate() {
  return _tick_rate;
}
