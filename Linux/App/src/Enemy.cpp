#include "Enemy.hpp"

#include <iostream>

Enemy::Enemy(double y, bool is_left)
    : x(is_left ? 0 : Scene::Width()), y(y), is_left(is_left) {}

void Enemy::setup() {}

void Enemy::update() {
  if (is_left) {
    x += 10.0;
  } else {
    x -= 10.0;
  }
  hit_collision = Circle(x, y, TextureAsset(U"enemy").size().x / 2);
}

void Enemy::draw() {
  hit_collision.draw(Palette::Blue);
  TextureAsset(U"enemy").drawAt(x, y);
}