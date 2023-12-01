// NPC.cpp
#include "npc.h"
#include <cmath>
#include <GL/glut.h>

NPC::NPC() {
    // Initialize NPC position
    npcX = static_cast<float>(rand() % 250);
    npcY = static_cast<float>(rand() % 250);

    // Initialize NPC direction
    directionX = (rand() % 2 == 0) ? 1 : -1; // Randomly set initial direction in x-axis
    directionY = (rand() % 2 == 0) ? 1 : -1; // Randomly set initial direction in y-axis
}

NPC::~NPC() {}

void NPC::drawCircle(float radius) {
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0, 0.0, 0.0); // Set circle color to red
    glVertex2f(npcX, npcY);  // Center of circle
    for (int i = 0; i <= 360; i++) {
        float angle = i * 3.14159 / 180;
        glVertex2f(npcX + radius * cos(angle), npcY + radius * sin(angle));
    }
    glEnd();
}

void NPC::displayCircle() {
    drawCircle(30);
}

void NPC::move() {
    // Move the NPC in the specified direction
    npcX += speed * directionX; // Move in x-axis
    npcY += speed * directionY; // Move in y-axis

    // Bounce back when hitting the screen borders
    if (npcX < 0 || npcX > 250) {
        directionX = -directionX; // Reverse direction in x-axis
    }

    if (npcY < 0 || npcY > 250) {
        directionY = -directionY; // Reverse direction in y-axis
    }

    glutPostRedisplay();
}
