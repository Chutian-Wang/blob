#ifndef VEC2_H
#define VEC2_H

struct Vec2 {
  float x;
  float y;
  Vec2(float x, float y) : x(x), y(y){};
  Vec2() : x(0.0f), y(0.0f){};

  float norm();
  // This will negate self and return self.
  Vec2& negate();
  // all operations supported + - scaler *
  Vec2& operator+=(const Vec2& rhs);
  Vec2& operator-=(const Vec2& rhs);
  Vec2& operator*=(float rhs);
};

Vec2 operator+(Vec2 lhs, const Vec2& rhs);
Vec2 operator-(Vec2 lhs, const Vec2& rhs);
Vec2 operator*(float lhs, Vec2 rhs);
Vec2 operator*(Vec2 lhs, float rhs);

#endif  // VEC2_H