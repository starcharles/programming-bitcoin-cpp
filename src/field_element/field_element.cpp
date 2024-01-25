#include <iostream>
#include "field_element.h"

FieldElement::FieldElement(int num, int prime) : num_(num), prime_(prime) {
  if (num_ >= prime_ || num_ < 0) {
    throw std::invalid_argument("Num is not in field range 0 to p-1");
  }
}

FieldElement::FieldElement(const FieldElement& other) : num_(other.num_), prime_(other.prime_) {}

FieldElement& FieldElement::operator=(const FieldElement& other) {
  if (this == &other) {
    return *this;
  }
  num_ = other.num_;
  prime_ = other.prime_;
  return *this;
}

bool FieldElement::operator==(const FieldElement& other) const {
  return other.num() == num_ && other.prime() == prime_;
}

bool FieldElement::operator!=(const FieldElement& other) const {
  return !(*this == other);
}

FieldElement FieldElement::operator+(const FieldElement& other) const {
  if(prime_ != other.prime()) {
    throw std::invalid_argument("invalid prime");
  }

  return FieldElement((num_ + other.num()) % prime_, prime_);
}

FieldElement FieldElement::operator-(const FieldElement& other) const {
  if(prime_ != other.prime()) {
    throw std::invalid_argument("invalid prime");
  }

  return FieldElement((num_ - other.num()) % prime_, prime_);
}

FieldElement FieldElement::operator*(const FieldElement& other) const {
  if(prime_ != other.prime()) {
    throw std::invalid_argument("invalid prime");
  }

  return FieldElement((num_ * other.num()) % prime_, prime_);
}

FieldElement FieldElement::operator/(const FieldElement& other) const {
  if(prime_ != other.prime()) {
    throw std::invalid_argument("invalid prime");
  }

  return FieldElement((num_*(other.num()^(other.prime() - 2))) % prime_, prime_);
}

FieldElement FieldElement::operator^(const int exponent) const {
  int n = exponent;
  while (n < 0)
  {
    n += prime_ - 1;
  }
  
  auto pow = static_cast<int>(std::pow(num_, exponent)) % prime_;
  return FieldElement(pow, prime_);
}

int FieldElement::num() const {
  return num_;
}

int FieldElement::prime() const {
  return prime_;
}