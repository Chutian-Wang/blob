#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Player.h"
#include "npc.h"

class Game {
 private:
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

  const std::vector<Blob>& get_blobs() {return this->blobs;}
  const Player& get_player() {return this->player;}
};

#endif // GAME_H