#ifndef PLAYER_H
#define PLAYER_H

#include "Blob.h"
#include "Vec2.h"

class Player : public Blob {
 private:
  // squared is equivalent to mass
  float radius;
  Color color;
  bool is_dead;

  Vec2 pos;
  Vec2 velocity;

 public:
  Player(float radius, Vec2 pos, Vec2 velocity, Color color);
  virtual ~Player(){};
  virtual void render();
  // This function gets key input and
  // updates the player velocity
  virtual void update(const Game& game);
};

#endif  // PLAYER_H