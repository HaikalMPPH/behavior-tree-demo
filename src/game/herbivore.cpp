#include "game/herbivore.hpp"
#include "game/game.hpp"
#include "std_includes.hpp"
#

Herbivore::Herbivore(Game* g, Vector2 p, Color c, uint8_t tr, float v)
  : _mov_actor {MovableActor(p, c, v)}
  , _agent {Agent(tr)} 
  , _game {g}
  , _hunger {100.0f}
  , _hunger_decrement {1.0f}
{
  //Create actions
  create_action();
  //Craete Condition
  create_condition();
  // Create behvaior tree
  create_behavior();
}

Herbivore::~Herbivore() {
}

void
Herbivore::update() {
  wrap_around();
  diminish_hunger();
  std::cout << "Hunger: " << _hunger << std::endl;
}

void
Herbivore::ai_update() {
  _agent.update();
}

void
Herbivore::render() {
  _mov_actor.render();
}

void
Herbivore::create_action() {
  _move_to_direction = new Action([this](){
    std::cout << "is moving..." << std::endl;
    static float ms = 0.0f;
    static float move_duration = (float)GetRandomValue(1, 4);

    _mov_actor.move_to(_game->get_frame_delta() * _agent.get_tick_rate());

    if (ms >= move_duration) {
      ms = 0.0f;
      
      // get new random move duration
      move_duration = (float)GetRandomValue(1, 4);    
      return BehaviorStatus::NodeSuccess;
    }

    ms += _game->get_frame_delta() * _agent.get_tick_rate();

    return BehaviorStatus::NodeRunning;
  });

  _set_random_directon = new Action([this](){
    std::cout << "finding random direction..." << std::endl;
    _mov_actor.set_dir(
        Vector2 {
          (float)GetRandomValue(-10, 10),
          (float)GetRandomValue(-10, 10)
        }
    );

    return BehaviorStatus::NodeSuccess;
  });

  _idle = new Action([this](){
    _mov_actor.set_color(YELLOW);
    static float ms = 0.0f;
    static float wait_limit = (float)GetRandomValue(1, 4);
    std::cout << "is idling..." << std::endl;

    if (ms >= wait_limit) {
      ms = 0.0f;
      wait_limit = (float)GetRandomValue(1, 4);
      return BehaviorStatus::NodeSuccess;
    }

    ms += _game->get_frame_delta() * _agent.get_tick_rate();

    return BehaviorStatus::NodeRunning;
  });

  _get_food_direction = new Action([this](){
    _mov_actor.set_dir(
      Vector2Subtract(
        _game->_food.get_position(), 
        _mov_actor.get_position()
      )
    );
    return BehaviorStatus::NodeSuccess;
  });

  _move_and_eat = new Action([this](){
    _mov_actor.move_to(_game->get_frame_delta() * _agent.get_tick_rate());
    if (
      // TODO - Find a way to tell if the agent have reached a
      // destination with vector math.
      // NOTE - Look at Vector2Distance function in raylib.
      true
    ) {
      std::cout << "FOOOODDD!!!!" << std::endl;
      _hunger = 100.0f;
      return BehaviorStatus::NodeSuccess;
    }

    return BehaviorStatus::NodeRunning;
  });
}

void
Herbivore::create_condition() {
  _is_hungry = new Condition([this](){
    if (_hunger <= _hunger_threshold) {
      _mov_actor.set_color(BROWN);
      std::cout << "HUNGRY!! >:(" << std::endl;
      return true;
    }

    _mov_actor.set_color(RED);
    return false;
  });
}

void
Herbivore::create_behavior() {
  _agent.set_btb(new BehaviorTreeBuilder());

  _agent.get_btb()
    ->root(new Selector())
      ->composite(new Sequence())
        ->decorator(new Invert())
          ->condition(_is_hungry)
          ->end()
        ->action(_set_random_directon)
        ->action(_move_to_direction)
        ->action(_idle)
        ->end()
      ->composite(new Sequence())
        ->condition(_is_hungry)
        ->action(_get_food_direction)
        ->action(_move_and_eat);

  _agent.create_bt();
}

void
Herbivore::wrap_around() {
  // wrapt around the screen
  if (_mov_actor.get_position().y < 0.0f) {
    _mov_actor.set_position(
      Vector2 {
        _mov_actor.get_position().x,
        _game->get_win_dimension().y
      }
    );
  }
  if (_mov_actor.get_position().y > _game->get_win_dimension().y) {
    _mov_actor.set_position(
      Vector2 {
        _mov_actor.get_position().x,
        0.0f
      }
    );
  }

  if (_mov_actor.get_position().x < 0.0f) {
    _mov_actor.set_position(
      Vector2 {
        _game->get_win_dimension().x,
        _mov_actor.get_position().y
      }
    );
  }

  if (_mov_actor.get_position().x > _game->get_win_dimension().x) {
    _mov_actor.set_position(
      Vector2 {
        0.0f,
        _mov_actor.get_position().y
      }
    );
  }
}

void
Herbivore::diminish_hunger() {
  _hunger -= 
    _hunger_decrement * _game->get_frame_delta() * _agent.get_tick_rate();
}
