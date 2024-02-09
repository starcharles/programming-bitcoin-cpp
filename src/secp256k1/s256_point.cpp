#include <secp256k1/s256_point.h>

S256Point::S256Point(const S256Field &x, const S256Field &y)
    : Point(x, y, A, B) {}
S256Point::S256Point(const Point &p) : Point(p) {}

S256Point S256Point::operator*(const int512 &coefficient) const {
  auto coef = coefficient % N;
  return S256Point(Point::operator*(coef));
}

S256Point operator*(const int512 &coefficient, const S256Point &p) {
  return p * coefficient;
}