#include <util/uint256.h>

uint256::uint256(const int value) {
  value_ = boost::multiprecision::uint256_t(value);
};
uint256::uint256(const std::string value) {
  value_ = boost::multiprecision::uint256_t(value);
};
uint256::uint256(const boost::multiprecision::uint256_t &value)
    : value_(value) {}
uint256::uint256(const uint256 &other) : value_(other.value_) {}
uint256 &uint256::operator=(const uint256 &other) {
  value_ = other.value_;
  return *this;
}
uint256 &uint256::operator=(const boost::multiprecision::uint256_t &value) {
  value_ = value;
  return *this;
}
uint256 uint256::operator+(const uint256 &other) const {
  return uint256(value_ + other.value_);
}
uint256 uint256::operator-(const uint256 &other) const {
  return uint256(value_ - other.value_);
}
uint256 uint256::operator*(const uint256 &other) const {
  return uint256(value_ * other.value_);
}
uint256 uint256::operator/(const uint256 &other) const {
  return uint256(value_ / other.value_);
}
uint256 uint256::operator%(const uint256 &other) const {
  return uint256(value_ % other.value_);
}
bool uint256::operator==(const uint256 &other) const {
  return value_ == other.value_;
}
bool uint256::operator!=(const uint256 &other) const {
  return value_ != other.value_;
}
bool uint256::operator<(const uint256 &other) const {
  return value_ < other.value_;
}
bool uint256::operator<=(const uint256 &other) const {
  return value_ <= other.value_;
}
bool uint256::operator>(const uint256 &other) const {
  return value_ > other.value_;
}
bool uint256::operator>=(const uint256 &other) const {
  return value_ >= other.value_;
}
uint256 &uint256::operator+=(const uint256 &other) {
  value_ += other.value_;
  return *this;
}
uint256 &uint256::operator-=(const uint256 &other) {
  value_ -= other.value_;
  return *this;
}
uint256 &uint256::operator*=(const uint256 &other) {
  value_ *= other.value_;
  return *this;
}
uint256 &uint256::operator%=(const uint256 &other) {
  value_ %= other.value_;
  return *this;
}

boost::multiprecision::uint256_t uint256::value() const { return value_; }