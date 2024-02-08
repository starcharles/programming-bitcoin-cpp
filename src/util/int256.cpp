#include <util/int256.h>

int256::int256(const int value) {
  value_ = boost::multiprecision::int256_t(value);
};
int256::int256(const std::string value) {
  value_ = boost::multiprecision::int256_t(value);
};
int256::int256(const boost::multiprecision::int256_t &value) : value_(value) {}
int256::int256(const int256 &other) : value_(other.value_) {}
int256 &int256::operator=(const int256 &other) {
  value_ = other.value_;
  return *this;
}
int256 &int256::operator=(const boost::multiprecision::int256_t &value) {
  value_ = value;
  return *this;
}
int256 int256::operator+(const int256 &other) const {
  return int256(value_ + other.value_);
}
int256 int256::operator-(const int256 &other) const {
  return int256(value_ - other.value_);
}
int256 int256::operator*(const int256 &other) const {
  return int256(value_ * other.value_);
}
int256 int256::operator/(const int256 &other) const {
  return int256(value_ / other.value_);
}
int256 int256::operator%(const int256 &other) const {
  return int256(value_ % other.value_);
}
bool int256::operator==(const int256 &other) const {
  return value_ == other.value_;
}
bool int256::operator!=(const int256 &other) const {
  return value_ != other.value_;
}
bool int256::operator<(const int256 &other) const {
  return value_ < other.value_;
}
bool int256::operator<=(const int256 &other) const {
  return value_ <= other.value_;
}
bool int256::operator>(const int256 &other) const {
  return value_ > other.value_;
}
bool int256::operator>=(const int256 &other) const {
  return value_ >= other.value_;
}
int256 &int256::operator+=(const int256 &other) {
  value_ += other.value_;
  return *this;
}
int256 &int256::operator-=(const int256 &other) {
  value_ -= other.value_;
  return *this;
}
int256 &int256::operator*=(const int256 &other) {
  value_ *= other.value_;
  return *this;
}
int256 &int256::operator%=(const int256 &other) {
  value_ %= other.value_;
  return *this;
}

boost::multiprecision::int256_t int256::value() const { return value_; }

std::ostream &operator<<(std::ostream &os, const int256 &u) {
  os << "uint256(" << u.value() << ")";
  return os;
}