#include "engine/debug.hpp"

Debug::Debug(Actor* refActor) 
  : _statusMessage {""}
  , _statusVal {0.0f}
  , _refActor {refActor}
{}

Debug::~Debug() {}

void
Debug::SetStatus(const char* status, float statusVal) {
  _statusMessage = status;
  _statusVal = static_cast<float>(statusVal);
}

void
Debug::ShowStatus() {
  // raylib draw text
  DrawText(
      TextFormat("%s: %f", _statusMessage, *_statusVal)
      , _refActor->GetPosition().x - 30.0f
      , _refActor->GetPosition().y - 30.0f
      , 12.0f
      , BLACK
  );
}

