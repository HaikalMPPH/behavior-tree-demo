#ifndef GAME_HPP
#define GAME_HPP

#include <raylib.h>
#include "std_includes.hpp"
#include "engine/agent.hpp"
#include "game/herbivore.hpp"
#include "game/food.hpp"


class Game {
private:
  unsigned int _winW;
  unsigned int _winH;
  // Time between a frame to another.
  float _frameDelta;

///////////////// CUSTOM MEMBERS //////////////////////////////////////
  Herbivore _herb1;
  Herbivore _herb2;
  Herbivore _herb3;
  Herbivore _herb4;
///////////////////////////////////////////////////////////////////////
public:
  Food food; // Temporary
  Game(uint16_t w, uint16_t h);
  ~Game();

  // On initialization.
  void Init();

  // Runs continuosly the update and render method.
  void Run();

  // Runs every frame.
  void Update();      // Logic update.
  void Render();      // Render update.
  void AiUpdate();   // AI Update.
                      
  float GetFrameDelta();
  Vector2 GetWinDimension();

  // Called when the game is closed. For resources cleaning.
  void Shutdown();
};

#endif
