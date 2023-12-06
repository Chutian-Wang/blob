#include "Vec2.h"

#include <cmath>

float Vec2::norm() { return sqrt(x * x + y * y); }

Vec2& Vec2::negate() {
  this->x = -this->x;
  this->y = -this->y;
  return *this;
}

Vec2& Vec2::operator+=(const Vec2& other) {
  this->x += other.x;
  this->y += other.y;
  return *this;
}

Vec2& Vec2::operator-=(const Vec2& other) {
  this->x -= other.x;
  this->y -= other.y;
  return *this;
}

Vec2& Vec2::operator*=(float other) {
  this->x *= other;
  this->y *= other;
  return *this;
}

Vec2 operator+(Vec2 lhs, const Vec2& rhs) { return lhs += rhs; }

Vec2 operator-(Vec2 lhs, const Vec2& rhs) { return lhs -= rhs; }

Vec2 operator*(float lhs, Vec2 rhs) { return rhs *= lhs; }

Vec2 operator*(Vec2 lhs, float rhs) { return lhs *= rhs; }
