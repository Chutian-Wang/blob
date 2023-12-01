#include "npc.h"
#include <cmath>
#include <GL/glut.h>

NPC::NPC() {
    // Initialize NPC position
    npcX = static_cast<float>(rand() % 250);
    npcY = static_cast<float>(rand() % 250);
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
    // Move the NPC randomly
    npcX += static_cast<float>(rand() % 5 - 2); // Random movement in x-axis
    npcY += static_cast<float>(rand() % 5 - 2); // Random movement in y-axis

    // Keep NPC within the screen bounds
    if (npcX < 0) npcX = 0;
    if (npcX > 250) npcX = 250;
    if (npcY < 0) npcY = 0;
    if (npcY > 250) npcY = 250;
    // You can add additional logic based on NPC's behavior

    // Trigger redisplay to update the screen
    glutPostRedisplay();
}
