#include "game/game.hpp"

Game::Game(uint16_t w, uint16_t h) 
  : _winW {w} 
  , _winH {h} 
  , _frameDelta {0}
  , _herb1 {Herbivore(this, {512.0f, 384.0f}, DARKGREEN, 5.0f, 100.0f)} 
  , _herb2 {Herbivore(this, {512.0f, 384.0f}, DARKGREEN, 5.0f, 100.0f)} 
  , _herb3 {Herbivore(this, {512.0f, 384.0f}, DARKGREEN, 5.0f, 100.0f)} 
  , _herb4 {Herbivore(this, {512.0f, 384.0f}, DARKGREEN, 5.0f, 100.0f)} 
  , food {Food({800.0f, 450.0f}, GREEN)}
{
}

Game::~Game() {
  Shutdown();
}


void 
Game::Init() {
  InitWindow(_winW, _winH, "Behavior Tree Demo");
}

void 
Game::Run() {
  while(!WindowShouldClose()) {
    _frameDelta = GetFrameTime();

    Render();
    Update();
    AiUpdate();
  }

  CloseWindow();
}

void 
Game::Update() {
  _herb1.Update();
  _herb2.Update();
  _herb3.Update();
  _herb4.Update();
}

void 
Game::AiUpdate() {
  _herb1.AiUpdate();
  _herb2.AiUpdate();
  _herb3.AiUpdate();
  _herb4.AiUpdate();
}

void 
Game::Render() {
BeginDrawing();

  ClearBackground(LIGHTGRAY);
  _herb1.Render();
  _herb2.Render();
  _herb3.Render();
  _herb4.Render();
  food.Render();

EndDrawing();
}

float
Game::GetFrameDelta() {
  return _frameDelta;
}

Vector2
Game::GetWinDimension() {
  return Vector2 {(float)_winW, (float)_winH};
}

void 
Game::Shutdown() {
}
