#ifndef PROGRAMMING_BITCOIN_UTIL_UINT256_H
#define PROGRAMMING_BITCOIN_UTIL_UINT256_H

#include <boost/multiprecision/cpp_int.hpp>

class int256 {
private:
  boost::multiprecision::int256_t value_;

public:
  int256() = default;
  int256(const int value);
  int256(const std::string value);
  int256(const boost::multiprecision::int256_t &value);
  int256(const int256 &other);
  int256 &operator=(const int256 &other);
  int256 &operator=(const boost::multiprecision::int256_t &value);
  int256 operator+(const int256 &other) const;
  int256 operator-(const int256 &other) const;
  int256 operator*(const int256 &other) const;
  int256 operator/(const int256 &other) const;
  int256 operator%(const int256 &other) const;
  bool operator==(const int256 &other) const;
  bool operator!=(const int256 &other) const;
  bool operator<(const int256 &other) const;
  bool operator<=(const int256 &other) const;
  bool operator>(const int256 &other) const;
  bool operator>=(const int256 &other) const;
  int256 &operator+=(const int256 &other);
  int256 &operator-=(const int256 &other);
  int256 &operator*=(const int256 &other);
  int256 &operator%=(const int256 &other);
  boost::multiprecision::int256_t value() const;
};

std::ostream &operator<<(std::ostream &os, const int256 &u);

#endif // PROGRAMMING_BITCOIN_UTIL_UINT256_H