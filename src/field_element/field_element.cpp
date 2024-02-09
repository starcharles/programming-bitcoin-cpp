#include <field_element/field_element.h>
#include <iostream>
#include <util/math.h>

FieldElement::FieldElement(int512 num, int512 prime)
    : num_(num), prime_(prime) {
  if (num >= prime || num < 0) {
    throw std::invalid_argument("Num is not in field range 0 to p-1");
  }
}

FieldElement::FieldElement(const FieldElement &other) noexcept
    : num_(other.num_), prime_(other.prime_) {}

FieldElement &FieldElement::operator=(const FieldElement &other) noexcept {
  if (this == &other) {
    return *this;
  }
  num_ = other.num_;
  prime_ = other.prime_;
  return *this;
}

bool FieldElement::operator==(const FieldElement &other) const noexcept {
  return other.num() == num_ && other.prime() == prime_;
}

bool FieldElement::operator!=(const FieldElement &other) const noexcept {
  return !(*this == other);
}

FieldElement FieldElement::operator+(const FieldElement &other) const {
  if (prime_ != other.prime()) {
    throw std::invalid_argument("invalid prime");
  }

  return FieldElement((num_ + other.num()) % prime_, prime_);
}

FieldElement FieldElement::operator-(const FieldElement &other) const {
  if (prime_ != other.prime()) {
    throw std::invalid_argument("invalid prime");
  }

  auto num = (num_ - other.num()) % prime_;
  while (num < 0) {
    num += prime_;
  }

  return FieldElement(num, prime_);
}

FieldElement FieldElement::operator*(int512 scalar) const {
  return FieldElement((num_ * scalar) % prime_, prime_);
}

FieldElement operator*(int512 scalar, const FieldElement &f) {
  return f * scalar;
}

FieldElement FieldElement::operator*(const FieldElement &other) const {
  if (prime_ != other.prime()) {
    throw std::invalid_argument("invalid prime");
  }

  return FieldElement((num_ * other.num()) % prime_, prime_);
}

FieldElement FieldElement::operator/(const FieldElement &other) const {
  if (prime_ != other.prime()) {
    throw std::invalid_argument("invalid prime");
  }
  int512 num =
      (num_ * math::my_pow(other.num(), other.prime() - 2, other.prime())) %
      prime_;
  return FieldElement(num, prime_);
}

FieldElement FieldElement::operator^(const int512 exponent) const {
  int512 n = exponent;
  while (n < 0) {
    n += prime_ - 1;
  }
  int512 num = math::my_pow(num_, n, prime_);
  return FieldElement(num, prime_);
}

int512 FieldElement::num() const { return num_; }

int512 FieldElement::prime() const { return prime_; }

std::ostream &operator<<(std::ostream &os, const FieldElement &f) {
  os << "FieldElement(" << f.num() << ", " << f.prime() << ")";
  return os;
}
