#ifndef GAME_H
#define GAME_H

#include <vector>

#include "NPC.h"
#include "Player.h"

class Game {
 private:
  int score;
  int window_size_x;
  int window_size_y;
  bool start;
  Player player;
  // NPCs and food particles
  std::vector<Blob> blobs;

 public:
  void init();
  void start();
  void update();
  void render();

  std::vector<Blob>& get_blobs() { return this->blobs; }
  Player& get_player() { return this->player; }
};

#endif  // GAME_H