#include <GL/gl.h>
#include <GL/glut.h>
#include <memory>

#include "lib/Game.h"

void init(int argc, char** argv);
void display();
void reshape(int w, int h);

std::unique_ptr<Game> game = std::make_unique<Game>();

int main(int argc, char** argv) {
  init(argc, argv);
  return 0;
}

void init(int argc, char** argv) {
  // Initialise GLUT with command-line parameters.
  glutInit(&argc, argv);

  // Set Display Mode
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

  // Set the window size
  glutInitWindowSize(500, 500);

  // Set the window position
  glutInitWindowPosition(100, 100);

  // Create the window
  glutCreateWindow("Blob");

  // Call "display" function
  glutDisplayFunc(display);

  // Reshape the window
  glutReshapeFunc(reshape);

  // Enter the GLUT event loop
  glutMainLoop();
}

void display() {
  if (game == nullptr) {
    return;
  }
  // Clear all pixels
  glClear(GL_COLOR_BUFFER_BIT);

  // draw all the blobs
  game->render();

  // Display the thing drawn
  glFlush();
}

void reshape(int w, int h) {
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, 500, 500, 0);
  glMatrixMode(GL_MODELVIEW);
}