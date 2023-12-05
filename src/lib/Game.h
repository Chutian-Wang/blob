#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Player.h"
#include "NPC.h"

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
};

#endif // GAME_H