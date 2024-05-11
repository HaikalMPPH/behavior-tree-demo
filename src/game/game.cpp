#include "game.hpp"
#include "agent.hpp"

Game::Game(unsigned int w, unsigned int h) 
    : _win_w {w} 
    , _win_h {h} 
    , _frame_delta {0} 
    , _wanderer {Agent(this, 5.0f)} 
    , _wanderer2 {Agent(this, 5.0f)} 
    , _wanderer3 {Agent(this, 5.0f)} 
    , _wanderer4 {Agent(this, 5.0f)} 
    , _wanderer5 {Agent(this, 5.0f)} 
    , _wanderer6 {Agent(this, 5.0f)} {}

Game::~Game() {
  shutdown();
}

float 
Game::get_frame_delta() {
  return _frame_delta;
}

float
Game::get_game_width() {
  return _win_w;
}

float
Game::get_game_height() {
  return _win_h;
}

void Game::init() {
  InitWindow(_win_w, _win_h, "Behavior Tree Demo");
}

void Game::run() {
  while(!WindowShouldClose()) {
    _frame_delta = GetFrameTime();

    render();
    update();
    ai_update();
  }
  CloseWindow();
}

void Game::update() {
  _wanderer.update();
  _wanderer2.update();
  _wanderer3.update();
  _wanderer4.update();
  _wanderer5.update();
  _wanderer6.update();
}

void Game::ai_update() {
  _wanderer.bt_update();
  _wanderer2.bt_update();
  _wanderer3.bt_update();
  _wanderer4.bt_update();
  _wanderer5.bt_update();
  _wanderer6.bt_update();
}

void Game::render() {
BeginDrawing();

  ClearBackground(LIGHTGRAY);
  _wanderer.render();
  _wanderer2.render();
  _wanderer3.render();
  _wanderer4.render();
  _wanderer5.render();
  _wanderer6.render();

EndDrawing();
}

void Game::shutdown() {
}
