#include "player.h"

#include <cmath>

Player& Player::getInstance() {
  static Player instance;
  return instance;
}

Player::Player() : playerX(125.0), playerY(125.0) {
  // Set up the callback functions
  // glutMouseFunc(mouse);
  glutMotionFunc(motion);
}

Player::~Player() {}

void Player::drawCircle(float radius) {
  glBegin(GL_TRIANGLE_FAN);
  glColor3f(0.0, 0.0, 1.0);      // Set circle color to blue
  glVertex2f(playerX, playerY);  // Center of circle
  for (int i = 0; i <= 360; i++) {
    float angle = i * 3.14159 / 180;
    glVertex2f(playerX + radius * cos(angle), playerY + radius * sin(angle));
  }
  glEnd();
}

void Player::displayCircle() {
  // glClear(GL_COLOR_BUFFER_BIT);
  drawCircle(30);
  // glFlush();
}

// This function is for actually clicking on the mouse
// void Player::mouse(int button, int state, int x, int y) {
//   if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
//     // Set player position based on mouse click
//     Player& player = getInstance();
//     player.playerX = x;
//     player.playerY = 250 - y;
//     glutPostRedisplay();
//   }
// }

void Player::motion(int x, int y) {
  // Update player position while mouse is moved
  Player& player = getInstance();
  player.playerX = x;
  player.playerY = 250 - y;
  glutPostRedisplay();
}