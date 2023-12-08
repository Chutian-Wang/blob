#ifndef BASICS_H
#define BASICS_H

#include <GL/gl.h>
#include <GL/glut.h>

namespace Basics {
void DrawCircle(float x, float y, float radius, const Color& color,
                int segments = 16);
void DrawLine(float x1, float y1, float x2, float y2, const Color& color);
void DrawText(float x, float y, const Color& color, float a = 1.0f,
              float scale = 1.0f);
}  // namespace Basics

#endif  // BASICS_H