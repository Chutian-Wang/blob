#ifndef BLOB_H
#define BLOB_H

#include "Color.h"
#include "Vec2.h"

class Game;

class Blob {
  friend class NPC;
  friend class Player;
  friend class Food;

 public:
  // squared is equivalent to mass
  float radius;
  Color color;

  Vec2 pos;
  Vec2 velocity;

 public:
  Blob(float radius, Vec2 pos, Vec2 velocity, Color color)
      : radius(radius), color(color), pos(pos), velocity(velocity){};
  virtual ~Blob(){};

  virtual void render() = 0;

  // This function gets key input and
  // updates the player velocity
  virtual void update(Game& game) = 0;
};

#endif  // BLOB_H