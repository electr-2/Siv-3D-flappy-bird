#include <Siv3D.hpp>
#include <iostream>
#include <vector>

#include "Enemy.hpp"
#include "Player.hpp"

std::vector<Enemy> enemys = {};
Player player = Player();
Stopwatch stopwatch(StartImmediately::No);  // trueで自動スタート

void dispatch_enemy() {
  bool is_left = RandomBool();
  int random_y = Random(0, Scene::Height());

  enemys.emplace_back(random_y, is_left);

  enemys.back().setup();
}

void reset_game() {
  enemys.clear();
  player.setup();
  stopwatch.restart();
}

void Main() {
  Window::Resize(1280, 720);
  Scene::SetBackground(Palette::Skyblue);

  int interval = 1;  // 敵を出現させる間隔（秒）
  double accumlated_time = 0.0;
  const Font font{FontMethod::MSDF, 48};

  TextureAsset::Register(U"enemy", U"😁"_emoji);
  TextureAsset::Register(U"player", U"🤓"_emoji);

  stopwatch.start();

  while (System::Update()) {
    player.draw();
    player.update();
    // enemys_update
    for (Enemy& enemy : enemys) {
      enemy.update();
      enemy.draw();
      if (enemy.hit_collision.intersects(player.hit_collision) ||
          !player.is_in_screen()) {
        reset_game();
        break;
      }
    }
    // timer
    accumlated_time += Scene::DeltaTime();
    if (interval <= accumlated_time) {
      accumlated_time -= interval;
      dispatch_enemy();
    }
    double seconds = stopwatch.sF();  // タイマー表示（小数第1位まで）
    font(U"Time: {:.1f}"_fmt(seconds)).draw(20, 20, Palette::Black);
  }
}