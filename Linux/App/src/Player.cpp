#include "Player.hpp"

Player::Player(int _x, int _y) {
  x = _x;
  y = _y;
}

void Player::update() {
  std::cout << "Playerのupdateが呼ばれました。" << std::endl;
}

void Player::draw() {
  std::cout << "Playerのdrawが呼ばれました。" << std::endl;
}

void Player::showXY() {
  std::cout << "PlayerのshowXYが呼ばれました。 x:" << x << " y:" << y
            << std::endl;
}
