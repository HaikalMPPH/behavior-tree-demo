#include <game/game.hpp>
#include <std_includes.hpp>

int main() {
  std::srand(std::time(nullptr));
  Game game(1366, 768);

  game.init();
  game.run();
  game.shutdown();

  return 0;
}
