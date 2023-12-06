#ifndef GAME_H
#define GAME_H

#include <vector>

#include "NPC.h"
#include "player.h"

class Game {
  static const int NPC_AMOUNT  = 10;
  static const int FOOD_AMOUNT = 50;

  static const int WIN_WIDTH  = 500;
  static const int WIN_HEIGHT = 500;

 private:
  int score;
  bool start;
  Player player;
  // NPCs and food particles
  std::vector<Blob> blobs;

 public:
  void init();
  void start_game();
  void update();
  void render();

  const std::vector<Blob>& get_blobs() { return this->blobs; }
  const Player& get_player() { return this->player; }
};

#endif  // GAME_H