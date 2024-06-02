#include "game/herbivore.hpp"
#include "game/game.hpp"
#include "std_includes.hpp"

Herbivore::Herbivore(Game* g, Vector2 p, Color c, uint8_t tr, float v)
  : _movActor {MovableActor(p, c, v)}
  , _agent {Agent(tr)} 
  , _game {g}
  , _debug {Debug(&_movActor)}
  , _ms {0.0f}
  , _msLimit {0.0f}
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
  _ms += _game->GetFrameDelta();
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
    _movActor.MoveTo(_game->GetFrameDelta() * _agent.GetTickRate());
    _debug.SetStatus("Moving: ", &_ms);

    if (_ms >= _msLimit) {
      ResetMs();
      return BehaviorStatus::NodeSuccess;
    }

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
    _debug.SetStatus("Idling: ", &_ms);
    if (_ms >= _msLimit) {
      ResetMs();
      return BehaviorStatus::NodeSuccess;
    }

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

void
Herbivore::ResetMs() {
  _ms = 0.0f;
  _msLimit = static_cast<float>(GetRandomValue(0, 4));
}
