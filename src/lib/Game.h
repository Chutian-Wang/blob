#ifndef GAME_H
#define GAME_H

#include <map>
#include <memory>
#include <vector>

#include "Blob.h"
#include "NPC.h"
#include "Player.h"

#define WORLD_SIZE 4
#define WIN_SCORE 100

class Game {
  static const int NPC_AMOUNT = 100;
  static const int FOOD_AMOUNT = 500;

  static const int WIN_WIDTH = 800;
  static const int WIN_HEIGHT = 800;

 private:
  int score;
  bool running;
  bool movement;
  bool ended;
  std::unique_ptr<Player> player;
  // NPCs and food particles
  std::vector<std::unique_ptr<Blob>> blobs;

 public:
  Game();
  ~Game(){};
  void init();
  void update();
  void render();

  const std::vector<std::unique_ptr<Blob>>& get_blobs() { return this->blobs; }
  const std::unique_ptr<Player>& get_player() { return this->player; }

  constexpr int get_window_x() { return WIN_WIDTH; }
  constexpr int get_window_y() { return WIN_HEIGHT; }
  bool get_movement() { return movement; }
};

#endif  // GAME_H