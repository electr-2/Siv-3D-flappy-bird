#include "Enemy.hpp"
#include "Player.hpp"

class GameScene {
 public:
  void setup();
  void update();
  void draw();
};

class Main : public GameScene {
 public:
  void setup();
  void update();
  void draw();

 private:
  int interval;
  double accumulated_time;
  Player player;
  std::vector<Enemy> enemys;
};

class Title : public GameScene {
 public:
  void setup();
  void update();
  void draw();
};