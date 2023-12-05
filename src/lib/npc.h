#ifndef NPC_H
#define NPC_H

#include <GL/gl.h>
#include <GL/glut.h>

#include "Player.h"

class NPC : Blob {
 public:
  NPC(flaot radius, Vec2 pos, Vec2 velocity, Color color);
  virtual ~NPC() {};
  virtual void render();
  virtual void update(const Game& game);
};

class Food : Blob {
 public:
  Food(flaot radius, Vec2 pos, Vec2 velocity, Color color);
  virtual ~Food() {};
  virtual void render();
  virtual void update(const Game& game) {};
}

#endif  // NPC_H
