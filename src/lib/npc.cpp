// NPC.cpp
#include "npc.h"

#include <GL/glut.h>

#include <cmath>

NPC::NPC() {
  // Initialize NPC position
  npcX = static_cast<float>(rand() % 250);
  npcY = static_cast<float>(rand() % 250);

  // Initialize NPC direction
  directionX =
      (rand() % 2 == 0) ? 1 : -1;
  directionY =
      (rand() % 2 == 0) ? 1 : -1;
}

NPC::~NPC() {}

void NPC::drawCircle(float radius) {
  glBegin(GL_TRIANGLE_FAN);
  glColor3f(1.0, 0.0, 0.0);
  glVertex2f(npcX, npcY);    // Center of circle
  for (int i = 0; i <= 360; i++) {
    float angle = i * 3.14159 / 180;
    glVertex2f(npcX + radius * cos(angle), npcY + radius * sin(angle));
  }
  glEnd();
}

void NPC::displayCircle() { drawCircle(30); }

void NPC::move() {
  npcX += speed * directionX;
  npcY += speed * directionY;

  // Bounce back when hitting the screen borders
  if (npcX < 0 || npcX > 250) {
    directionX = -directionX;
  }

  if (npcY < 0 || npcY > 250) {
    directionY = -directionY;
  }

  glutPostRedisplay();
}
