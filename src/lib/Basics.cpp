#include "Basics.h"
#include "Color.h"

#include <cmath>

void Basics::DrawCircle(float x, float y, float radius, const Color& color, int segments) {
    glColor3ub(color.r, color.g, color.b);
    glBegin(GL_TRIANGLE_FAN);

    for (int i = 0; i <= segments; ++i) {
        float theta = 2.0f * 3.141592653f * float(i) / float(segments);
        float dx = radius * cosf(theta);
        float dy = radius * sinf(theta);
        glVertex2f(x + dx, y + dy);
    }
    glEnd();
}
    
// void Basics::DrawLine(float x1, float y1, float x2, float y2, const Color& color) {
//     glColor3ub(color.r, color.g, color.b);
//     glBegin(GL_LINES);
//     glVertex2f(x1, y1);
//     glVertex2f(x2, y2);
//     glEnd();
// }

void Basics::DrawStartText(float x, float y, const Color& color) {
    glColor3ub(color.r, color.g, color.b);
    glRasterPos2f(x, y);

    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'S');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 't');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'a');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'r');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 't');
}

void Basics::DrawEndText(float x, float y, const Color& color) {
    glColor3ub(color.r, color.g, color.b);
    glRasterPos2f(x, y);

    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'G');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'a');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'm');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'e');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'o');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'v');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'e');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'r');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '.');
}