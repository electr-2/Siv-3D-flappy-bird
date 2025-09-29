#include "Player.hpp"

Player::Player() : y(0), vy(0) {}

void Player::setup() {
  y = Scene::Height() / 2;
  vy = 0.0;
  hit_collision =
      Circle(Scene::Center().x, y, TextureAsset(U"player").size().x / 2);
}

void Player::update() {
  vy += 0.3;
  y += vy;

  if (KeyUp.down()) {
    vy = -10.0;
  }
  hit_collision =
      Circle(Scene::Center().x, y, TextureAsset(U"player").size().x / 2);
}

void Player::draw() {
  hit_collision.draw(Palette::Red);
  TextureAsset(U"player").drawAt(Scene::Center().x, y);
}

bool Player::is_in_screen() { return (0 <= y && y <= Scene::Height()); }
