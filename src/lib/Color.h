#ifndef COLOR_H
#define COLOR_H

#define RED Color(255, 0, 0)
#define GREEN Color(0, 255, 0)
#define BLUE Color(0, 0, 255)

struct Color {
  int r, g, b;
  Color() : r(0), g(0), b(0) {}
  Color(int r, int g, int b) : r(r), g(g), b(b) {}
};

#endif