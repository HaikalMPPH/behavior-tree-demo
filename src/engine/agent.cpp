#include "engine/agent.hpp"
#include "game/game.hpp"
#include <raymath.h>

Agent::Agent(float tick_rate) 
    : btb {nullptr} 
    , bt {nullptr}
    , tick_rate {tick_rate} {}

Agent::~Agent() {
  cleanup();
}

void
Agent::update() {
  if (bt != nullptr) {
    bt->bt_update(tick_rate);
  }
}

void
Agent::cleanup() {
  if (btb != nullptr && bt != nullptr) {
    delete bt;
    delete btb;
    bt = nullptr;
    btb = nullptr;
  }
}
