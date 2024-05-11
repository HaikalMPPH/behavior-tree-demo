#include "game/game.hpp"

Game::Game(unsigned int w, unsigned int h) 
  : _win_w {w} 
  , _win_h {h} 
  , _frame_delta {0}
  , _herb1 {Herbivore(this, Vector2 {512.0f, 384.0f}, RED, 5.0f, 100.0f)} 
  , _food {Food(Vector2 {800.0f, 450.0f}, GREEN)}
{
}

Game::~Game() {
  shutdown();
}


void 
Game::init() {
  InitWindow(_win_w, _win_h, "Behavior Tree Demo");
}

void 
Game::run() {
  while(!WindowShouldClose()) {
    _frame_delta = GetFrameTime();

    render();
    update();
    ai_update();
  }

  CloseWindow();
}

void 
Game::update() {
  _herb1.update();
}

void 
Game::ai_update() {
  _herb1.ai_update();
}

void 
Game::render() {
BeginDrawing();

  ClearBackground(LIGHTGRAY);
  _herb1.render();
  _food.render();

EndDrawing();
}

float
Game::get_frame_delta() {
  return _frame_delta;
}

Vector2
Game::get_win_dimension() {
  return Vector2 {(float)_win_w, (float)_win_h};
}

void 
Game::shutdown() {
}
