#include <iostream>
#include <point.h>
#include <sstream>

#define ZERO FieldElement(0, 3)
#define INIFINITY_POINT Point(ZERO, ZERO, ZERO, ZERO)

Point::Point(FieldElement x, FieldElement y, FieldElement a, FieldElement b)
    : _x(x), _y(y), _a(a), _b(b) {
  if (y * y != x * x * x + a * x + b) {
    std::ostringstream oss;
    oss << "Point(" << x << ", " << y << ") is not on the curve";
    throw std::invalid_argument(oss.str());
  }
};

FieldElement Point::a() const { return _a; };

FieldElement Point::b() const { return _b; };

FieldElement Point::x() const { return _x; };

FieldElement Point::y() const { return _y; };

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
  if (IsInfinity(*this)) {
    return other;
  }

  // Case 0.1: other is the point at infinity, return self
  if (IsInfinity(other)) {
    return *this;
  }

  // Case 1: self.x == other.x, self.y != other.y return point at infinity
  if (_x == other.x() && _y != other.y()) {
    return INIFINITY_POINT;
  }

  // Case 2: self.x ≠ other.x return the result of the point addition formula
  if (_x != other.x()) {
    auto s = (other.y() - _y) / (other.x() - _x);
    auto x = s * s - _x - other.x();
    auto y = s * (_x - x) - _y;
    return Point(x, y, _a, _b);
  }

  // Case 3: self == other
  if (*this == other) {
    int prime = this->a().prime();
    auto s = ((FieldElement(3, prime) * _x * _x) + _a) /
             (FieldElement(2, prime) * _y);
    auto x = (s * s) - (FieldElement(2, prime) * _x);
    auto y = s * (_x - x) - _y;
    return Point(x, y, _a, _b);
  }

  // Case 4: self == other and y == ZERO
  if (*this == other && _y == ZERO) {
    return INIFINITY_POINT;
  }

  return INIFINITY_POINT;
};

bool IsInfinity(const Point &p) { return p == INIFINITY_POINT; };

std::ostream &operator<<(std::ostream &os, const Point &p) {
  if (IsInfinity(p)) {
    os << "Point(infinity)";
  } else {
    os << "Point(" << p.x() << ", " << p.y() << ")_" << p.a() << "_" << p.b();
  }
  return os;
};