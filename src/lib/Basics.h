#ifndef BASICS_H
#define BASICS_H

#include <GL/gl.h>
#include <GL/glut.h>

#include <string>

#include "Color.h"

namespace Basics {
void draw_circle(float x, float y, float radius, const Color& color,
                 int segments = 16);
void draw_line(float x1, float y1, float x2, float y2, const Color& color);
void draw_text(const std::string& test, float x, float y, const Color& color);
}  // namespace Basics

#endif  // BASICS_H