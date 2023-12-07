#ifndef PLAYER_H
#define PLAYER_H

#include "Blob.h"
#include "Color.h"
#include "Vec2.h"

#define PLAYER_ACCELERATION 0.1

class Player : public Blob {
 public:
  bool alive;

  Player(float radius, Vec2 pos, Vec2 velocity, Color color)
      : Blob(radius, pos, velocity, color), alive(true){};
  virtual ~Player(){};
  virtual void render();
  // This function gets key input and
  // updates the player velocity
  virtual void update(Game& game);
};

#endif  // PLAYER_H