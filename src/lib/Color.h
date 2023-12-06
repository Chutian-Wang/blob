#ifndef COLOR_H
#define COLOR_H

#define RED Color(255, 0, 0)
#define GREEN Color(0, 255, 0)
#define BLUE Color(0, 0, 255)

struct Color {
  int r, g, b;
  Color();
  Color(int r, int g, int b) : r(r), g(g), b(b) {}
};

#endif