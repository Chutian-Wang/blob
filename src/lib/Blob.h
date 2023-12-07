#ifndef BLOB_H
#define BLOB_H

#include "Color.h"
#include "Game.h"
#include "Vec2.h"

class Blob {
  friend class NPC;
  friend class Player;
  friend class Food;

 private:
  // squared is equivalent to mass
  float radius;
  Color color;

  Vec2 pos;
  Vec2 velocity;

 public:
  Blob(float radius, Vec2 pos, Vec2 velocity, Color color)
      : radius(radius), pos(pos), velocity(velocity), color(color){};
  virtual ~Blob(){};

  virtual void render() = 0;

  // This function gets key input and
  // updates the player velocity
  virtual void update(Game& game) = 0;
  virtual float get_radius() { return this->radius; }
  virtual void set_radius(float radius) { this->radius = radius; }

  virtual Vec2 get_pos() { return this->pos; }
  virtual Vec2 get_velocity() { return this->velocity; }
  virtual void set_pos(const Vec2& pos) { this->pos = pos; }
  virtual void set_velocity(const Vec2& velocity) { this->velocity = velocity; }
};

#endif  // BLOB_H