#include "agent.hpp"
#include "game.hpp"
#include <raymath.h>

Agent::Agent(Game* game, float tick_rate) 
    : AActor(game)
    , _btb {new BehaviorTreeBuilder()} 
    , _bt {nullptr} 
    , _tick_rate {tick_rate} 
    , _velocity {100.0f} {
  // Temporary init position.
  _position = {512.0f, 360.0f};

  // Init the Action Node
  init();

  // Behvaior tree toime!!!
  _btb->root(new Selector())
    ->composite(new Sequence())
      ->action(a_set_random_dir)
      ->action(a_move_to_dir)
      ->action(a_idle);


  _bt = _btb->create_tree();
}

Agent::~Agent() {
  cleanup();
}

void Agent::update() {
  // wrapt around the screen
  if (_position.y < 0.0f) {
    _position.y = _game->get_game_height();
  }
  if (_position.y > _game->get_game_height()) {
    _position.y = 0.0f;
  }
  if (_position.x < 0.0f) {
    _position.x = _game->get_game_width();
  }
  if (_position.x > _game->get_game_width()) {
    _position.x = 0.0f;
  }
}
void Agent::bt_update() {
  //_bt->bt_update(5.0f);
  _bt->bt_update(_tick_rate);
}

void Agent::render() {
  DrawCircleV(_position, 20, _color);
}

void Agent::cleanup() {
  delete _btb;
  delete _bt;
}

///////////////////// CUSTOM BEHAVIOR /////////////////////////////////
void Agent::init() {
  a_move_to_dir = new Action([this](){ 
    static float ms = 0.0f;
    static float ms_limit = (float)GetRandomValue(1, 3);
    //std::cout << "move_up ms: " << ms << std::endl;
    _color = RED;
    _position.x += 
      _move_direction.x * _velocity * _tick_rate * _game->get_frame_delta();
    _position.y += 
      _move_direction.y * _velocity * _tick_rate * _game->get_frame_delta();

    if (ms >= ms_limit) {
      ms = 0.0f;
      ms_limit = (float)GetRandomValue(1, 3);
      return BehaviorStatus::NodeSuccess;
    }
    ms += _game->get_frame_delta() * _tick_rate;// * 5.0f;

    return BehaviorStatus::NodeRunning;
  });


  a_idle = new Action([this](){ 
    static float ms = 0.0f;
    static float ms_limit = (float)GetRandomValue(1, 3);
    std::cout << "idle ms: " << ms << std::endl;
    _color = YELLOW;

    ms += _game->get_frame_delta() * _tick_rate; //* 5.0f;
    if (ms >= ms_limit) {
      ms = 0.0f;
      ms_limit = (float)GetRandomValue(1, 3);
      return BehaviorStatus::NodeSuccess;
    }
    return BehaviorStatus::NodeRunning;
  });

  a_set_random_dir = new Action([this](){
    _target_pos = Vector2Add(
        _position, 
        {(float)GetRandomValue(-10, 10)
        , (float)GetRandomValue(-10, 10)});
    _move_direction = 
      Vector2Normalize(Vector2Subtract(_target_pos, _position));
    return BehaviorStatus::NodeSuccess;
    
  });
}
///////////////////////////////////////////////////////////////////////
