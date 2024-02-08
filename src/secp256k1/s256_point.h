#ifndef PROGRAMMING_BITCOIN_S256_POINT_H
#define PROGRAMMING_BITCOIN_S256_POINT_H

#include <elliptic/point.h>
#include <secp256k1/s256_field.h>
#include <util/int256.h>

static const S256Field A(0);
static const S256Field B(7);
static const int256
    N("0xfffffffffffffffffffffffffffffffebaaedce6af48a03bbfd25e8cd0364141");

class S256Point : public Point {
public:
  S256Point(const S256Field &x, const S256Field &y);
  S256Point(const Point &p);
  S256Point operator*(const int256 &coefficient) const;
};

S256Point operator*(const int256 &coefficient, const S256Point &p);

#endif // PROGRAMMING_BITCOIN_S256_POINT_H