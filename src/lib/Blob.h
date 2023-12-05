#ifndef BLOB_H
#define BLOB_H

#include "Vec2.h"
#include "Color.h"
#include "Game.h"

class Blob {
 private:
  // squared is equivalent to mass
  float radius;
  Color color;

  Vec2 pos;
  Vec2 velocity;

 public:
  Blob() {};
  virtual ~Blob() {};

  virtual void render() = 0;

  // This function gets key input and
  // updates the player velocity
  virtual void update(const Game& game) = 0;
  virtual float get_radius() {return this->radius;}
  virtual void  set_radius(float radius) {this-> radius = radius;}

  virtual const Vec2& get_pos() {return this->pos;}
  virtual const Vec2& get_velocity() {return this->velocity;}
  virtual void set_pos(const Vec2& pos) {this->pos = pos;}
  virtual void set_velocity(const Vec2& velocity) {this->velocity = velocity;}
};

#endif // BLOB_H