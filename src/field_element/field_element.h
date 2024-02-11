#ifndef PROGRAMMING_BITCOIN_FIELD_ELEMENT_H
#define PROGRAMMING_BITCOIN_FIELD_ELEMENT_H

#include <iostream>
#include <util/int512.h>

class FieldElement {
private:
  int512 num_;
  int512 prime_;

public:
  FieldElement() = delete;
  FieldElement(int512 num, int512 prime);
  FieldElement(const FieldElement &other) noexcept;
  FieldElement &operator=(const FieldElement &other) noexcept;
  bool operator==(const FieldElement &other) const noexcept;
  bool operator!=(const FieldElement &other) const noexcept;
  FieldElement operator+(const FieldElement &other) const;
  FieldElement operator-(const FieldElement &other) const;
  FieldElement operator*(const int512 scalar) const;
  FieldElement operator*(const FieldElement &other) const;
  FieldElement operator/(const FieldElement &other) const;
  FieldElement operator^(const int512 exponent) const;
  int512 num() const;
  int512 prime() const;
};

FieldElement operator*(int512 scalar, const FieldElement &f);
std::ostream &operator<<(std::ostream &os, const FieldElement &f);

#endif // PROGRAMMING_BITCOIN_FIELD_ELEMENT_H