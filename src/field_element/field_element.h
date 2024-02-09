#ifndef PROGRAMMING_BITCOIN_FIELD_ELEMENT_H
#define PROGRAMMING_BITCOIN_FIELD_ELEMENT_H

#include <iostream>
#include <util/int256.h>

class FieldElement {
private:
  int256 num_;
  int256 prime_;

public:
  FieldElement() = delete;
  FieldElement(int256 num, int256 prime);
  FieldElement(const FieldElement &other) noexcept;
  FieldElement &operator=(const FieldElement &other) noexcept;
  bool operator==(const FieldElement &other) const noexcept;
  bool operator!=(const FieldElement &other) const noexcept;
  FieldElement operator+(const FieldElement &other) const;
  FieldElement operator-(const FieldElement &other) const;
  FieldElement operator*(const int256 scalar) const;
  FieldElement operator*(const FieldElement &other) const;
  FieldElement operator/(const FieldElement &other) const;
  FieldElement operator^(const int256 exponent) const;
  int256 num() const;
  int256 prime() const;
};

FieldElement operator*(int256 scalar, const FieldElement &f);
int256 my_pow(int256 base, int256 exponent, int256 prime);
std::ostream &operator<<(std::ostream &os, const FieldElement &f);

#endif // PROGRAMMING_BITCOIN_FIELD_ELEMENT_H