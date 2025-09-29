#include <Siv3D.hpp>

class Enemy {
 public:
  Enemy(double y, bool is_left);
  void setup();
  void update();
  void draw();
  Circle hit_collision;

 private:
  double x;
  double y;
  const bool is_left;
};
