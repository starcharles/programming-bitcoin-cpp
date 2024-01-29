#ifndef PROGRAMMING_BITCOIN_POINT_H
#define PROGRAMMING_BITCOIN_POINT_H

#include <iostream>

#define MY_INFINITY std::numeric_limits<int>::max()

class Point {
private:
  int _x;
  int _y;
  int _a;
  int _b;

public:
  Point() = delete;
  Point(int x, int y, int a, int b);
  bool operator==(const Point &other) const;
  bool operator!=(const Point &other) const;
  Point operator+(const Point &other) const;
  int a() const;
  int b() const;
  int x() const;
  int y() const;
};

bool IsInfinity(const Point &p);

std::ostream &operator<<(std::ostream &os, const Point &p);

#endif // PROGRAMMING_BITCOIN_POINT_H