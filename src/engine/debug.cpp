#include "engine/debug.hpp"

Debug::Debug(MovableActor* refMovActor)
  : _statusMessage {""}
  , _statusVal {nullptr}
  , _refMovActor {refMovActor}
{}

Debug::~Debug() {}

void
Debug::SetStatus(const char* status, float* statusVal) {
  _statusMessage = status;
  _statusVal = statusVal;
}

void
Debug::ShowStatus() {
  if (_statusVal != nullptr) {
    // raylib draw text
    DrawText(
        TextFormat("%s: %f", _statusMessage, *_statusVal)
        , _refMovActor->GetPosition().x - 30.0f
        , _refMovActor->GetPosition().y - 30.0f
        , 12.0f
        , BLACK
    );
  }
}

