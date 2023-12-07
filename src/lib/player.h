#ifndef PLAYER_H
#define PLAYER_H

#include "Blob.h"
#include "Vec2.h"

#define PLAYER_ACCELERATION 0.1

class Player : Blob {
 public:
  Player(float radius, Vec2 pos, Vec2 velocity, Color color)
      : Blob(radius, pos, velocity, color){};
  virtual ~Player(){};
  virtual void render();
  // This function gets key input and
  // updates the player velocity
  virtual void update(Game& game);
};

#endif  // PLAYER_H