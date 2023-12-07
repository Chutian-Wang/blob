#ifndef GAME_H
#define GAME_H

#include <map>
#include <memory>
#include <vector>

#include "Blob.h"
#include "NPC.h"
#include "Player.h"

class Game {
  static const int NPC_AMOUNT = 10;
  static const int FOOD_AMOUNT = 50;

  static const int WIN_WIDTH = 500;
  static const int WIN_HEIGHT = 500;

 private:
  int score;
  bool start;
  std::unique_ptr<Player> player;
  // NPCs and food particles
  std::vector<std::unique_ptr<Blob>> blobs;

 public:
  Game();
  ~Game() {};
  void init();
  void start_game();
  void update();
  void render();

  const std::vector<std::unique_ptr<Blob>>& get_blobs() { return this->blobs; }
  const std::unique_ptr<Player>& get_player() { return this->player; }

  constexpr int get_window_x() { return WIN_WIDTH; }
  constexpr int get_window_y() { return WIN_HEIGHT; }
};

#endif  // GAME_H