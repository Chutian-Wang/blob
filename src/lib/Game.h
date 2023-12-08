#ifndef GAME_H
#define GAME_H

#include <map>
#include <memory>
#include <vector>

#include "Blob.h"
#include "NPC.h"
#include "Player.h"

#define WORLD_SIZE 4

class Game {
  static const int NPC_AMOUNT = 10;
  static const int FOOD_AMOUNT = 500;

  static const int WIN_WIDTH = 800;
  static const int WIN_HEIGHT = 800;

 private:
  int score;
  bool running;
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
  bool get_game_status() {return running; }
};

#endif  // GAME_H