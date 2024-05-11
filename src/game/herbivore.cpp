#include "game/herbivore.hpp"
#include "game/game.hpp"

Herbivore::Herbivore(Game* g, Vector2 p, Color c, float tr, float v)
  : actor {Actor(p, c)}
  , agent {Agent(tr)} 
  , game {g}
  , velocity {v}
  , direction {0.0f, 0.0f}
  , hunger {100.0f}
  , hunger_decrement {1.0f}
{
  //Create actions
  create_action();
  //Craete Condition
  create_condition();
  // Create behvaior tree
  create_behavior();
}

Herbivore::~Herbivore() {}

void
Herbivore::update() {
  wrap_around();
  diminish_hunger();
  std::cout << "Hunger: " << hunger << std::endl;
}

void
Herbivore::ai_update() {
  agent.update();
}

void
Herbivore::render() {
  actor.render();
}

void
Herbivore::create_action() {
  move_to_direction = new Action([this](){
    actor.color = RED;
    std::cout << "is moving..." << std::endl;
    static float ms = 0.0f;
    static float move_duration = (float)GetRandomValue(1, 4);

    actor.position.x += 
      direction.x * velocity * game->frame_delta * agent.tick_rate;

    actor.position.y += 
      direction.y * velocity * game->frame_delta * agent.tick_rate;

    if (ms >= move_duration) {
      ms = 0.0f;
      
      // get new random move duration
      move_duration = (float)GetRandomValue(1, 4);    
      return BehaviorStatus::NodeSuccess;
    }

    ms += game->frame_delta * agent.tick_rate;

    return BehaviorStatus::NodeRunning;
  });

  set_random_directon = new Action([this](){
    std::cout << "finding random direction..." << std::endl;
    direction.x = (float)GetRandomValue(-10, 10);
    direction.y = (float)GetRandomValue(-10, 10);
    direction = Vector2Normalize(direction);

    return BehaviorStatus::NodeSuccess;
  });

  idle = new Action([this](){
    actor.color = YELLOW;
    static float ms = 0.0f;
    static float wait_limit = (float)GetRandomValue(1, 4);
    std::cout << "is idling..." << std::endl;

    if (ms >= wait_limit) {
      ms = 0.0f;
      wait_limit = (float)GetRandomValue(1, 4);
      return BehaviorStatus::NodeSuccess;
    }

    ms += game->frame_delta * agent.tick_rate;

    return BehaviorStatus::NodeRunning;
  });
}

void
Herbivore::create_condition() {
  is_hungry = new Condition([this](){
    if (hunger <= hunger_threshold) {
      std::cout << "HUNGRY!! >:(" << std::endl;
      actor.color = BROWN;
      return true;
    }

    return false;
  });
}

void
Herbivore::create_behavior() {
  agent.btb = new BehaviorTreeBuilder();
  agent.btb->root(new Selector())
    ->composite(new Sequence())
      ->decorator(new Invert())
        ->condition(is_hungry)
        ->end()
      ->action(set_random_directon)
      ->action(move_to_direction)
      ->action(idle)
      ->end()
    ->composite(new Sequence())
      ->condition(is_hungry);

  agent.bt = agent.btb->create_tree();
}

void
Herbivore::wrap_around() {
  // wrapt around the screen
  if (actor.position.y < 0.0f) {
    actor.position.y = game->win_h;
  }
  if (actor.position.y > game->win_h) {
    actor.position.y = 0.0f;
  }
  if (actor.position.x < 0.0f) {
    actor.position.x = game->win_w;
  }
  if (actor.position.x > game->win_w) {
    actor.position.x = 0.0f;
  }
}

void
Herbivore::diminish_hunger() {
  hunger -= hunger_decrement * game->frame_delta * agent.tick_rate;
}
