#include <Siv3D.hpp>
#include <iostream>

class Player {
 public:
  int x, y;
  Player(int _x, int _y);
  void update();
  void draw();
  void showXY();
};