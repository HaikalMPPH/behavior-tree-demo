#include "game/game.hpp"
#include "engine/agent.hpp"

Game::Game(unsigned int w, unsigned int h) 
  : win_w {w} 
  , win_h {h} 
  , frame_delta {0}
  , herb1 {Herbivore(this, Vector2 {512.0f, 384.0f}, RED, 5.0f, 100.0f)} 
{
}

Game::~Game() {
  shutdown();
}


void 
Game::init() {
  InitWindow(win_w, win_h, "Behavior Tree Demo");
}

void 
Game::run() {
  while(!WindowShouldClose()) {
    frame_delta = GetFrameTime();

    render();
    update();
    ai_update();
  }

  CloseWindow();
}

void 
Game::update() {
  herb1.update();
}

void 
Game::ai_update() {
  herb1.ai_update();
}

void 
Game::render() {
BeginDrawing();

  ClearBackground(LIGHTGRAY);
  herb1.render();

EndDrawing();
}

void 
Game::shutdown() {
}
