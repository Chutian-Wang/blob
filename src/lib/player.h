#ifndef PLAYER_H
#define PLAYER_H

#include <GL/gl.h>
#include <GL/glut.h>

class Player {
 private:
  Player();
  ~Player();

  float playerX;
  float playerY;

 public:
  static Player& getInstance();

  void drawCircle(float radius);
  void displayCircle();
  // static void mouse(int button, int state, int x, int y);
  static void motion(int x, int y);
};

#endif  // PLAYER_H