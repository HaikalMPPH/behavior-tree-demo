#ifndef GAME_HPP
#define GAME_HPP

#include <raylib.h>
#include "std_includes.hpp"
#include "engine/agent.hpp"
#include "game/herbivore.hpp"


struct Game {
  unsigned int win_w;
  unsigned int win_h;
  // Time between a frame to another.
  float frame_delta;

///////////////// CUSTOM MEMBERS //////////////////////////////////////
  Herbivore herb1;
///////////////////////////////////////////////////////////////////////

  Game(unsigned int w, unsigned int h);
  ~Game();

  // On initialization.
  void init();

  // Runs continuosly the update and render method.
  void run();

  // Runs every frame.
  void update();      // Logic update.
  void render();      // Render update.
  void ai_update();   // AI Update.

  // Called when the game is closed. For resources cleaning.
  void shutdown();
};

#endif
