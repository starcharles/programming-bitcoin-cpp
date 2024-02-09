#include <util/int512.h>

int512::int512(const int value) {
  value_ = boost::multiprecision::int512_t(value);
};
int512::int512(const std::string value) {
  value_ = boost::multiprecision::int512_t(value);
};
int512::int512(const boost::multiprecision::int512_t &value) : value_(value) {}
int512::int512(const int512 &other) : value_(other.value_) {}
int512 &int512::operator=(const int512 &other) {
  if (this == &other)
    return *this; // handle self assignment
  value_ = other.value_;
  return *this;
}
int512 &int512::operator=(const boost::multiprecision::int512_t &value) {
  value_ = value;
  return *this;
}
int512 int512::operator+(const int512 &other) const {
  return int512(value_ + other.value_);
}
int512 int512::operator-(const int512 &other) const {
  return int512(value_ - other.value_);
}
int512 int512::operator*(const int512 &other) const {
  return int512(value_ * other.value_);
}
int512 int512::operator/(const int512 &other) const {
  return int512(value_ / other.value_);
}
int512 int512::operator%(const int512 &other) const {
  return int512(value_ % other.value_);
}
bool int512::operator==(const int512 &other) const {
  return value_ == other.value_;
}
bool int512::operator!=(const int512 &other) const {
  return value_ != other.value_;
}
bool int512::operator<(const int512 &other) const {
  return value_ < other.value_;
}
bool int512::operator<=(const int512 &other) const {
  return value_ <= other.value_;
}
bool int512::operator>(const int512 &other) const {
  return value_ > other.value_;
}
bool int512::operator>=(const int512 &other) const {
  return value_ >= other.value_;
}
int512 &int512::operator+=(const int512 &other) {
  value_ += other.value_;
  return *this;
}
int512 &int512::operator-=(const int512 &other) {
  value_ -= other.value_;
  return *this;
}
int512 &int512::operator*=(const int512 &other) {
  value_ *= other.value_;
  return *this;
}
int512 &int512::operator%=(const int512 &other) {
  value_ %= other.value_;
  return *this;
}

boost::multiprecision::int512_t int512::value() const { return value_; }

std::ostream &operator<<(std::ostream &os, const int512 &u) {
  os << "int512(" << std::hex << u.value() << ")";
  return os;
}