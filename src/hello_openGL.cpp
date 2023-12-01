#include <GL/gl.h>
#include <GL/glut.h>

#include "lib/npc.h"
#include "lib/player.h"

void display();
void init();
void moveNPCs();

// Create instances of NPC class
NPC npc1;
NPC npc2;
NPC npc3;

int main(int argc, char** argv) {
  // Initialise GLUT with command-line parameters.
  glutInit(&argc, argv);

  // Set Display Mode
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

  // Set the window size
  glutInitWindowSize(250, 250);

  // Set the window position
  glutInitWindowPosition(100, 100);

  // Create the window
  glutCreateWindow("A Simple OpenGL Windows Application with GLUT");

  // Call init (initialise GLUT
  init();

  // Call "display" function
  glutDisplayFunc(display);

  glutIdleFunc(moveNPCs);

  // glutMouseFunc(Player::getInstance().mouse);
  glutMotionFunc(Player::getInstance().motion);

  // Enter the GLUT event loop
  glutMainLoop();

  return 0;
}

void display() {
  // Clear all pixels
  glClear(GL_COLOR_BUFFER_BIT);

  // draw white polygon (rectangle) with corners at
  //  (0.25, 0.25) and (0.75, 0.75)
  glColor3f(1.0, 1.0, 1.0);
  glBegin(GL_POLYGON);
  glVertex3f(0.25, 0.25, 0.1);
  glVertex3f(0.75, 0.25, 0.1);
  glVertex3f(0.75, 0.75, 0.1);
  glVertex3f(0.25, 0.75, 0.1);
  glEnd();

  // Draw blue circle from the player class
  Player::getInstance().displayCircle();

  // Draw red circles from the NPC instances
  npc1.displayCircle();
  npc2.displayCircle();
  npc3.displayCircle();

  // Display  drawn objects
  glFlush();
}

void init() {
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0.0, 250.0, 0.0, 250.0, -1.0, 1.0);
}

void moveNPCs() {
  npc1.move();
  npc2.move();
  npc3.move();

  glutPostRedisplay();
}
