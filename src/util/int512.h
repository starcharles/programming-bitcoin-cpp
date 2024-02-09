#ifndef PROGRAMMING_BITCOIN_UTIL_INT512_H
#define PROGRAMMING_BITCOIN_UTIL_INT512_H

#include <boost/multiprecision/cpp_int.hpp>

class int512 {
private:
  boost::multiprecision::int512_t value_;

public:
  int512() = default;
  int512(const int value);
  int512(const std::string value);
  int512(const boost::multiprecision::int512_t &value);
  int512(const int512 &other);
  int512 &operator=(const int512 &other);
  int512 &operator=(const boost::multiprecision::int512_t &value);
  int512 operator+(const int512 &other) const;
  int512 operator-(const int512 &other) const;
  int512 operator*(const int512 &other) const;
  int512 operator/(const int512 &other) const;
  int512 operator%(const int512 &other) const;
  bool operator==(const int512 &other) const;
  bool operator!=(const int512 &other) const;
  bool operator<(const int512 &other) const;
  bool operator<=(const int512 &other) const;
  bool operator>(const int512 &other) const;
  bool operator>=(const int512 &other) const;
  int512 &operator+=(const int512 &other);
  int512 &operator-=(const int512 &other);
  int512 &operator*=(const int512 &other);
  int512 &operator%=(const int512 &other);
  boost::multiprecision::int512_t value() const;
};

std::ostream &operator<<(std::ostream &os, const int512 &u);

#endif // PROGRAMMING_BITCOIN_UTIL_INT512_H