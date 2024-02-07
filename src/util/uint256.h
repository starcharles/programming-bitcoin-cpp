#include <boost/multiprecision/cpp_int.hpp>

class uint256 {
private:
  boost::multiprecision::uint256_t value_;

public:
  uint256() = default;
  uint256(const int value) {
    value_ = boost::multiprecision::uint256_t(value);
  };
  uint256(const std::string value) {
    value_ = boost::multiprecision::uint256_t(value);
  };
  uint256(const boost::multiprecision::uint256_t &value) : value_(value) {}
  uint256(const uint256 &other) : value_(other.value_) {}
  uint256 &operator=(const uint256 &other) {
    value_ = other.value_;
    return *this;
  }
  uint256 &operator=(const boost::multiprecision::uint256_t &value) {
    value_ = value;
    return *this;
  }
  uint256 operator+(const uint256 &other) const {
    return uint256(value_ + other.value_);
  }
  uint256 operator-(const uint256 &other) const {
    return uint256(value_ - other.value_);
  }
  uint256 operator*(const uint256 &other) const {
    return uint256(value_ * other.value_);
  }
  uint256 operator/(const uint256 &other) const {
    return uint256(value_ / other.value_);
  }
  uint256 operator%(const uint256 &other) const {
    return uint256(value_ % other.value_);
  }
  bool operator==(const uint256 &other) const { return value_ == other.value_; }
  bool operator!=(const uint256 &other) const { return value_ != other.value_; }
  bool operator<(const uint256 &other) const { return value_ < other.value_; }
  bool operator<=(const uint256 &other) const { return value_ <= other.value_; }
  bool operator>(const uint256 &other) const { return value_ > other.value_; }
  bool operator>=(const uint256 &other) const { return value_ >= other.value_; }
  uint256 &operator+=(const uint256 &other) {
    value_ += other.value_;
    return *this;
  }
  uint256 &operator-=(const uint256 &other) {
    value_ -= other.value_;
    return *this;
  }
  uint256 &operator*=(const uint256 &other) {
    value_ *= other.value_;
    return *this;
  }
  uint256 &operator%=(const uint256 &other) {
    value_ %= other.value_;
    return *this;
  }

  boost::multiprecision::uint256_t value() const { return value_; }
};

std::ostream &operator<<(std::ostream &os, const uint256 &u) {
  os << "uint256(" << u.value() << ")";
  return os;
}