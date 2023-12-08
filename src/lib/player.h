#ifndef PLAYER_H
#define PLAYER_H

#include "Vec2.h"
#include "Blob.h"

class Player : Blob {
 public:
  Player(float radius, Vec2 pos, Vec2 velocity, Color color);
  virtual ~Player() {};
  virtual void render();
  // This function gets key input and
  // updates the player velocity
  virtual void update(const Game& game);
};

#endif  // PLAYER_H