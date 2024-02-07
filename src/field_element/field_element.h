#ifndef PROGRAMMING_BITCOIN_FIELD_ELEMENT_H
#define PROGRAMMING_BITCOIN_FIELD_ELEMENT_H

#include <iostream>

class FieldElement {
private:
  uint256 num_;
  uint256 prime_;

public:
  FieldElement(uint256 num, uint256 prime);
  FieldElement(const FieldElement &other) noexcept;
  FieldElement &operator=(const FieldElement &other) noexcept;
  bool operator==(const FieldElement &other) const noexcept;
  bool operator!=(const FieldElement &other) const noexcept;
  FieldElement operator+(const FieldElement &other) const;
  FieldElement operator-(const FieldElement &other) const;
  FieldElement operator*(const uint256 scalar) const;
  FieldElement operator*(const FieldElement &other) const;
  FieldElement operator/(const FieldElement &other) const;
  FieldElement operator^(const uint256 exponent) const;
  uint256 num() const;
  uint256 prime() const;
};

FieldElement operator*(uint256 scalar, const FieldElement &f);
uint256 my_pow(uint256 base, uint256 exponent, uint256 prime);
std::ostream &operator<<(std::ostream &os, const FieldElement &f);

#endif // PROGRAMMING_BITCOIN_FIELD_ELEMENT_H