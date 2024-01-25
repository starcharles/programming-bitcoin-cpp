#include "point.h"

bool Point::operator==(const Point &other) const {
  return _x == other.x() && _y == other.y() && _a == other.a() &&
         _b == other.b();
};

bool Point::operator!=(const Point &other) const { return !(*this == other); };