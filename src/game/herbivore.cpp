#include "game/herbivore.hpp"
#include "game/game.hpp"
#include "std_includes.hpp"

Herbivore::Herbivore(Game* g, Vector2 p, Color c, uint8_t tr, float v)
  : _movActor {MovableActor(p, c, v)}
  , _agent {Agent(tr)} 
  , _game {g}
  , _debug {_movActor.GetActor()}
  , _hunger {100.0f}
  , _hungerThreshold {1.0f}
{
  //Create actions
  CreateAction();
  //Craete Condition
  CreateCondition();
  // Create behvaior tree
  CreateBehavior();
}

Herbivore::~Herbivore() {
}

void
Herbivore::Update() {
  WrapAround();
  DiminishHunger();
  _debug.ShowStatus();
}

void
Herbivore::AiUpdate() {
  _agent.Update();
}

void
Herbivore::Render() {
  _movActor.Render();
}

void
Herbivore::CreateAction() {
  _moveToDirection = new Action([this](){
    static float ms = 0.0f;
    static float moveDuration = (float)GetRandomValue(1, 4);

    _movActor.MoveTo(_game->GetFrameDelta() * _agent.GetTickRate());
    _debug.SetStatus("Moving: ", &ms);

    if (ms >= moveDuration) {
      ms = 0.0f;
      
      // get new random move duration
      moveDuration = (float)GetRandomValue(1, 4);    
      return BehaviorStatus::NodeSuccess;
    }

    ms += _game->GetFrameDelta() * _agent.GetTickRate();

    return BehaviorStatus::NodeRunning;
  });

  _setRandomDirection = new Action([this](){
    _movActor.SetDir(
        Vector2 {
          (float)GetRandomValue(-10, 10),
          (float)GetRandomValue(-10, 10)
        }
    );

    return BehaviorStatus::NodeSuccess;
  });

  _idle = new Action([this](){
    static float ms = 0.0f;
    static float waitLimit = (float)GetRandomValue(1, 4);
    _debug.SetStatus("idling: ", &ms);

    if (ms >= waitLimit) {
      ms = 0.0f;
      waitLimit = (float)GetRandomValue(1, 4);
      return BehaviorStatus::NodeSuccess;
    }

    ms += _game->GetFrameDelta() * _agent.GetTickRate();

    return BehaviorStatus::NodeRunning;
  });

  _getFoodDirection = new Action([this](){
    _movActor.SetDir(
      Vector2Subtract(
        _game->food.GetPosition(), 
        _movActor.GetPosition()
      )
    );
    return BehaviorStatus::NodeSuccess;
  });

  _moveAndEat = new Action([this](){
    _movActor.MoveTo(_game->GetFrameDelta() * _agent.GetTickRate());
    _debug.SetStatus("Moving to food: ", &_hunger);

    if (
      Vector2Distance(_movActor.GetPosition(), _game->food.GetPosition()) <= 1.f
    ) {
      std::cout << "FOOOODDD!!!!" << std::endl;
      _hunger = 100.0f;
      return BehaviorStatus::NodeSuccess;
    }

    return BehaviorStatus::NodeRunning;
  });
}

void
Herbivore::CreateCondition() {

  // TODO - create a paralel AddComposite so it can simultaneously monitor
  // conditions and running actions
  _isHungry = new Condition([this](){
    if (_hunger <= _hungerThreshold) {
      _movActor.SetColor(BROWN);
      std::cout << "HUNGRY!! >:(" << std::endl;
      return true;
    }

    _movActor.SetColor(DARKGREEN);
    return false;
  });
}

void
Herbivore::CreateBehavior() {
  _agent.SetBTB(new BehaviorTreeBuilder());

  _agent.GetBTB()
    ->AddRoot(new Selector())
      ->AddComposite(new Sequence())
        ->AddDecorator(new Invert())
          ->AddCondition(_isHungry)
          ->End()
        ->AddAction(_setRandomDirection)
        ->AddAction(_moveToDirection)
        ->AddAction(_idle)
        ->End()
      ->AddComposite(new Sequence())
        ->AddCondition(_isHungry)
        ->AddAction(_getFoodDirection)
        ->AddAction(_moveAndEat);

  _agent.CreateBT();
}

void
Herbivore::WrapAround() {
  // wrapt around the screen
  if (_movActor.GetPosition().y < 0.0f) {
    _movActor.SetPosition({
        _movActor.GetPosition().x,
        _game->GetWinDimension().y
      });
  }
  if (_movActor.GetPosition().y > _game->GetWinDimension().y) {
    _movActor.SetPosition({
        _movActor.GetPosition().x,
        0.0f
    });
  }

  if (_movActor.GetPosition().x < 0.0f) {
    _movActor.SetPosition({
        _game->GetWinDimension().x,
        _movActor.GetPosition().y
    });
  }

  if (_movActor.GetPosition().x > _game->GetWinDimension().x) {
    _movActor.SetPosition({
        0.0f,
        _movActor.GetPosition().y
    });
  }
}

void
Herbivore::DiminishHunger() {
  _hunger -= 
    _hungerThreshold * _game->GetFrameDelta() * _agent.GetTickRate();
}
