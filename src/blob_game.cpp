// #define GL_SILENCE_DEPRECATION

#include <GL/freeglut.h>
#include <GL/gl.h>
#include <GL/glut.h>

#include <memory>

#include "lib/Controls.h"
#include "lib/Game.h"

void init(int argc, char** argv);
void display();
void reshape(int w, int h);
void timer(int);

std::unique_ptr<Game> game;

int main(int argc, char** argv) {
  init(argc, argv);
  return 0;
}

void init(int argc, char** argv) {
  // Initialise GLUT with command-line parameters.
  glutInit(&argc, argv);

  game = std::make_unique<Game>();

  // Set Display Mode
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

  // Set the window size
  glutInitWindowSize(800, 800);

  // Set the window position
  glutInitWindowPosition(100, 100);

  // Create the window
  glutCreateWindow("Blob");

  // Call "display" function
  glutDisplayFunc(display);

  // Gameloop update
  glutTimerFunc(30, timer, 0);

  // Bind keyboard callbacks
  glutKeyboardFunc(Controls::keypress_cb);
  glutKeyboardUpFunc(Controls::keyup_cb);

  // Enter the GLUT event loop
  glutMainLoop();
}

void timer(int) {
  game->update();
  glutPostRedisplay();
  glutTimerFunc(33, timer, 0);
}

void display() {
  if (!game) {
    return;
  }
  // Clear all pixels
  glClearColor(0.1, 0.2, 0.1, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);

  // draw all the blobs
  game->render();
  // Display the thing drawn
  glutSwapBuffers();
}