#include <field_element.h>
#include <iostream>

FieldElement::FieldElement(int num, int prime) : num_(num), prime_(prime) {
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

FieldElement FieldElement::operator*(int scalar) const {
  return FieldElement((num_ * scalar) % prime_, prime_);
}

FieldElement operator*(int scalar, const FieldElement &f) { return f * scalar; }

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
  int num =
      (num_ * my_pow(other.num(), other.prime() - 2, other.prime())) % prime_;
  return FieldElement(num, prime_);
}

FieldElement FieldElement::operator^(const int exponent) const {
  int n = exponent;
  while (n < 0) {
    n += prime_ - 1;
  }
  int num = my_pow(num_, n, prime_);
  return FieldElement(num, prime_);
}

int FieldElement::num() const { return num_; }

int FieldElement::prime() const { return prime_; }

std::ostream &operator<<(std::ostream &os, const FieldElement &f) {
  os << "FieldElement(" << f.num() << ", " << f.prime() << ")";
  return os;
}

int my_pow(int base, int exp, int mod) {
  int result = 1;
  for (int i = 0; i < exp; i++) {
    result *= base;
    result %= mod;
  }
  return result;
}