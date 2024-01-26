#include <cmath>
#include <point.h>

Point::Point(int x, int y, int a, int b) : _x(x), _y(y), _a(a), _b(b) {
  if (x == INFINITY && y == INFINITY) {
    return;
  }
  if (y * y != x * x * x + a * x + b) {
    throw std::invalid_argument("Point(" + std::to_string(x) + ", " +
                                std::to_string(y) + ") is not on the curve");
  }
};

int Point::a() const { return _a; };

int Point::b() const { return _b; };

int Point::x() const { return _x; };

int Point::y() const { return _y; };

bool Point::operator==(const Point &other) const {
  return _x == other.x() && _y == other.y() && _a == other.a() &&
         _b == other.b();
};

bool Point::operator!=(const Point &other) const { return !(*this == other); };

Point Point::operator+(const Point &other) const {
  if (_a != other.a() || _b != other.b()) {
    throw std::invalid_argument("Points must be on the same curve");
  }

  // Case 0.0: self is the point at infinity, return other
  if (isinf(_x) && isinf(_y)) {
    return other;
  }

  // Case 0.1: other is the point at infinity, return self
  if (isinf(other.x()) && isinf(other.y())) {
    return *this;
  }

  // Case 1: self.x == other.x, self.y != other.y return point at infinity
  if (_x == other.x() && _y != other.y()) {
    return Point(INFINITY, INFINITY, _a, _b);
  }

  // Case 2: self.x ≠ other.x return the result of the point addition formula
  if (_x != other.x()) {
    int s = (other.y() - _y) / (other.x() - _x);
    int x = s * s - _x - other.x();
    int y = s * (_x - x) - _y;
    return Point(x, y, _a, _b);
  }

  // Case 3: self == other
  if (*this == other) {
    int s = (3 * _x * _x + _a) / (2 * _y);
    int x = s * s - 2 * _x;
    int y = s * (_x - x) - _y;
    return Point(x, y, _a, _b);
  }

  // Case 4: self == other and y == 0
  if (*this == other && _y == 0) {
    return Point(INFINITY, INFINITY, _a, _b);
  }

  return Point(INFINITY, INFINITY, _a, _b);
};

std::ostream &operator<<(std::ostream &os, const Point &p) {
  if (p.x() == INFINITY && p.y() == INFINITY) {
    os << "Point(infinity)";
  } else {
    os << "Point(" << p.x() << ", " << p.y() << ")_" << p.a() << "_" << p.b();
  }
  return os;
};