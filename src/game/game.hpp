#ifndef GAME_HPP
#define GAME_HPP

#include <raylib.h>
#include "std_includes.hpp"
#include "engine/agent.hpp"
#include "game/herbivore.hpp"
#include "game/food.hpp"


class Game {
private:
  unsigned int _win_w;
  unsigned int _win_h;
  // Time between a frame to another.
  float _frame_delta;

///////////////// CUSTOM MEMBERS //////////////////////////////////////
  Herbivore _herb1;
///////////////////////////////////////////////////////////////////////
public:
  Food _food; // Temporary
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
                      
  float get_frame_delta();
  Vector2 get_win_dimension();

  // Called when the game is closed. For resources cleaning.
  void shutdown();
};

#endif
