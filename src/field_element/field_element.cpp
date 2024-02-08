#include <field_element/field_element.h>
#include <iostream>

FieldElement::FieldElement(uint256 num, uint256 prime)
    : num_(num), prime_(prime) {
  if (num_ >= prime_ || num_ < 0) {
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

FieldElement FieldElement::operator*(uint256 scalar) const {
  return FieldElement((num_ * scalar) % prime_, prime_);
}

FieldElement operator*(uint256 scalar, const FieldElement &f) {
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
  uint256 num =
      (num_ * my_pow(other.num(), other.prime() - 2, other.prime())) % prime_;
  return FieldElement(num, prime_);
}

FieldElement FieldElement::operator^(const uint256 exponent) const {
  uint256 n = exponent;
  while (n < 0) {
    n += prime_ - 1;
  }
  uint256 num = my_pow(num_, n, prime_);
  return FieldElement(num, prime_);
}

uint256 FieldElement::num() const { return num_; }

uint256 FieldElement::prime() const { return prime_; }

std::ostream &operator<<(std::ostream &os, const FieldElement &f) {
  os << "FieldElement(" << f.num() << ", " << f.prime() << ")";
  return os;
}

uint256 my_pow(uint256 base, uint256 exp, uint256 mod) {
  uint256 result = 1;
  for (uint256 i = 0; i < exp; i += 1) {
    result *= base;
    result %= mod;
  }
  return result;
}