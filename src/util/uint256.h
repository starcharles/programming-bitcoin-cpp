#ifndef PROGRAMMING_BITCOIN_UTIL_UINT256_H
#define PROGRAMMING_BITCOIN_UTIL_UINT256_H

#include <boost/multiprecision/cpp_int.hpp>

class uint256 {
private:
  boost::multiprecision::uint256_t value_;

public:
  uint256() = default;
  uint256(const int value);
  uint256(const std::string value);
  uint256(const boost::multiprecision::uint256_t &value);
  uint256(const uint256 &other);
  uint256 &operator=(const uint256 &other);
  uint256 &operator=(const boost::multiprecision::uint256_t &value);
  uint256 operator+(const uint256 &other) const;
  uint256 operator-(const uint256 &other) const;
  uint256 operator*(const uint256 &other) const;
  uint256 operator/(const uint256 &other) const;
  uint256 operator%(const uint256 &other) const;
  bool operator==(const uint256 &other) const;
  bool operator!=(const uint256 &other) const;
  bool operator<(const uint256 &other) const;
  bool operator<=(const uint256 &other) const;
  bool operator>(const uint256 &other) const;
  bool operator>=(const uint256 &other) const;
  uint256 &operator+=(const uint256 &other);
  uint256 &operator-=(const uint256 &other);
  uint256 &operator*=(const uint256 &other);
  uint256 &operator%=(const uint256 &other);
  boost::multiprecision::uint256_t value() const;
};

std::ostream &operator<<(std::ostream &os, const uint256 &u) {
  os << "uint256(" << u.value() << ")";
  return os;
}

#endif // PROGRAMMING_BITCOIN_UTIL_UINT256_H