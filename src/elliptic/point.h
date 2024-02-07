#ifndef PROGRAMMING_BITCOIN_POINT_H
#define PROGRAMMING_BITCOIN_POINT_H

#include <field_element.h>
#include <iostream>

#define ZERO FieldElement(0, 3)
#define INIFINITY_POINT Point(ZERO, ZERO, ZERO, ZERO)
class Point {
private:
  FieldElement _x;
  FieldElement _y;
  FieldElement _a;
  FieldElement _b;

public:
  Point() = delete;
  Point(FieldElement x, FieldElement y, FieldElement a, FieldElement b);
  bool operator==(const Point &other) const;
  bool operator!=(const Point &other) const;
  Point operator+(const Point &other) const;
  Point operator*(const int coefficient) const;
  FieldElement a() const;
  FieldElement b() const;
  FieldElement x() const;
  FieldElement y() const;
};

Point operator*(const int coefficient, const Point &p);

bool IsInfinity(const Point &p);

std::ostream &operator<<(std::ostream &os, const Point &p);

#endif // PROGRAMMING_BITCOIN_POINT_H