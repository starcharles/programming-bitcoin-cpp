#include <iostream>

class Point {
private:
  int _a;
  int _b;
  int _x;
  int _y;

public:
  Point() = delete;
  Point(int x, int y, int a, int b);
  bool operator==(const Point &other) const;
  bool operator!=(const Point &other) const;
  int a() const;
  int b() const;
  int x() const;
  int y() const;
};

Point::Point(int x, int y, int a, int b) : _x(x), _y(y), _a(a), _b(b) {
  if (y * y != x * x * x + a * x + b) {
    throw std::invalid_argument((x, y) + "is not on the curve");
  }
};

int Point::a() const { return _a; };

int Point::b() const { return _b; };

int Point::x() const { return _x; };

int Point::y() const { return _y; };