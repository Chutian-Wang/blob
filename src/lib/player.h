#ifndef PLAYER_H
#define PLAYER_H

#include "Vec2.h"
#include "Blob.h"

class Player : Blob {
 public:
  Player(flaot radius, Vec2 pos, Vec2 velocity, Color color);
  virtual ~Player() {};
  // This function gets key input and
  // updates the player velocity
  virtual void  update();
};

#endif  // PLAYER_H