#ifndef NPC_H
#define NPC_H

#include <GL/gl.h>
#include <GL/glut.h>

#include "Color.h"
#include "Blob.h"
#include "Vec2.h"

class Game;

class NPC : public Blob {
 public:
  NPC(float radius, Vec2 pos, Vec2 velocity, Color color);
  virtual ~NPC(){};
  virtual void render();
  virtual void update(const Game& game);
};

class Food : public Blob {
 public:
  Food(float radius, Vec2 pos, Vec2 velocity, Color color);
  virtual ~Food(){};
  virtual void render();
  virtual void update(const Game&){};
};

#endif  // NPC_H
