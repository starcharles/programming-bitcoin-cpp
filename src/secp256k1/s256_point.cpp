#include <consts/math.cpp>
#include <secp256k1/s256_point.h>
#include <util/math.h>

S256Point::S256Point(const S256Field &x, const S256Field &y)
    : Point(x, y, A, B) {}
S256Point::S256Point(const Point &p) : Point(p) {}

S256Point S256Point::operator*(const int512 &coefficient) const {
  auto coef = coefficient % N;
  return S256Point(Point::operator*(coef));
}

bool S256Point::verify(const int512 &z, const Signature &sig) const {
  auto s_inv = math::my_pow(sig.s(), N - 2, N);
  auto u = z * s_inv % N;
  auto v = sig.r() * s_inv % N;
  auto total = u * G + v * *this;
  return total.x().num() == sig.r();
}

S256Point operator*(const int512 &coefficient, const S256Point &p) {
  return p * coefficient;
}