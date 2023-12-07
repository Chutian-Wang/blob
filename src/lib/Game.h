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
  std::unique_ptr<Player> player;
  // NPCs and food particles
  std::vector<std::unique_ptr<Blob>> blobs;

 public:
  void init();
  void start_game();
  void update();
  void render();

  const std::vector<std::unique_ptr<Blob>>& get_blobs() { return this->blobs; }
  const std::unique_ptr<Player> get_player() const{ return player.get(); }
};

#endif  // GAME_H