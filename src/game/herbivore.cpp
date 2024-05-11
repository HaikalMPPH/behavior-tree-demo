#include "game/herbivore.hpp"
#include "game/game.hpp"

Herbivore::Herbivore(Game* g, Vector2 p, Color c, float tr, float v)
  : actor {Actor(p, c)}
  , agent {Agent(tr)} 
  , game {g}
  , velocity {v}
  , direction {}
{
  //Create actions
  create_action();

  // Create behvaior tree
  create_behavior();
}

Herbivore::~Herbivore() {}

void
Herbivore::update() {
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
    std::cout << "velocity: " << velocity << std::endl;
    std::cout << "frame dt: " << game->frame_delta << std::endl;
    std::cout << "dir x:" << direction.x << std::endl;
    std::cout << "dir y:" << direction.y << std::endl;
    std::cout << "pos x:" << actor.position.x << std::endl;
    std::cout << "pos y:" << actor.position.y << std::endl;
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
    std::cout << "ms: " << ms << std::endl;

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
Herbivore::create_behavior() {
  agent.btb = new BehaviorTreeBuilder();
  agent.btb->root(new Selector())
    ->composite(new Sequence())
      ->action(set_random_directon)
      ->action(move_to_direction)
      ->action(idle);

  agent.bt = agent.btb->create_tree();
}
