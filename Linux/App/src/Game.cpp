#include "Game.hpp"

void dispatch_enemy(std::vector<Enemy>& enemys) {
  bool is_left = RandomBool();
  int random_y = Random(0, Scene::Height());

  enemys.emplace_back(random_y, is_left);

  enemys.back().setup();
}