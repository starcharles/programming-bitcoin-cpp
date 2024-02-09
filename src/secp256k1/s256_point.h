#ifndef PROGRAMMING_BITCOIN_S256_POINT_H
#define PROGRAMMING_BITCOIN_S256_POINT_H

#include <elliptic/point.h>
#include <secp256k1/s256_field.h>
#include <util/int512.h>

#define A S256Field(0)
#define B S256Field(7)
#define N                                                                      \
  int512("1157920892373161954235709850086879078528375642790749043826051631415" \
         "18161494337")
class S256Point : public Point {
public:
  S256Point() = delete;
  S256Point(const S256Field &x, const S256Field &y);
  S256Point(const Point &p);
  S256Point operator*(const int512 &coefficient) const;
};

S256Point operator*(const int512 &coefficient, const S256Point &p);

#endif // PROGRAMMING_BITCOIN_S256_POINT_H