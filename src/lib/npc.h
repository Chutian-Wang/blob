#ifndef NPC_H
#define NPC_H

#include <GL/gl.h>
#include <GL/glut.h>

#include "Blob.h"
#include "Color.h"
#include "Vec2.h"

#define NPC_ACCELERATION 0.1

class NPC : public Blob {
 public:
  NPC(float radius, Vec2 pos, Vec2 velocity, Color color)
      : Blob(radius, pos, velocity, color) {}
  virtual ~NPC(){};
  virtual void render();
  virtual void update(Game& game);
};

class Food : public Blob {
 public:
  Food(float radius, Vec2 pos, Color color)
      : Blob(radius, pos, Vec2(0, 0), color) {}
  virtual ~Food(){};
  virtual void render();
  virtual void update(Game&){};
};

#endif  // NPC_H
