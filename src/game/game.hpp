#ifndef GAME_HPP
#define GAME_HPP

#include <raylib.h>
#include "agent.hpp"

class Agent;

class Game {
private:
  unsigned int _win_w;
  unsigned int _win_h;

  // Time between a frame to another.
  float _frame_delta;
////////////////////// GAME SPECIFIC ATTRIBUTES ///////////////////////
private:
  Agent _wanderer;
  Agent _wanderer2;
  Agent _wanderer3;
  Agent _wanderer4;
  Agent _wanderer5;
  Agent _wanderer6;
///////////////////////////////////////////////////////////////////////
public:
  Game(unsigned int w, unsigned int h);
  ~Game();

  // On initialization.
  void init();

  // Runs continuosly the update and render method.
  void run();

  // Runs every frame.
  void update();      // Logic update.
  void render();      // Render update.
  void ai_update(); // AI Update.

  // Get the ms passed between frame
  float get_frame_delta();

  // Get game width and height
  float get_game_width();
  float get_game_height();

  // Called when the game is closed. For resources cleaning.
  void shutdown();
};

#endif
