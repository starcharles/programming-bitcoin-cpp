#ifndef PROGRAMMING_BITCOIN_FIELD_ELEMENT_H
#define PROGRAMMING_BITCOIN_FIELD_ELEMENT_H

#include <iostream>

class FieldElement {
private:
  int num_;
  int prime_;

public:
  FieldElement(int num, int prime);
  FieldElement(const FieldElement &other) noexcept;
  FieldElement &operator=(const FieldElement &other) noexcept;
  bool operator==(const FieldElement &other) const noexcept;
  bool operator!=(const FieldElement &other) const noexcept;
  FieldElement operator+(const FieldElement &other) const;
  FieldElement operator-(const FieldElement &other) const;
  FieldElement operator*(const int scalar) const;
  FieldElement operator*(const FieldElement &other) const;
  FieldElement operator/(const FieldElement &other) const;
  FieldElement operator^(const int exponent) const;
  int num() const;
  int prime() const;
};

FieldElement operator*(int scalar, const FieldElement &f);
int my_pow(int base, int exponent, int prime);
std::ostream &operator<<(std::ostream &os, const FieldElement &f);

#endif // PROGRAMMING_BITCOIN_FIELD_ELEMENT_H