
#include <boost/test/included/unit_test.hpp>
#include <point.h>

using namespace std;

FieldElement elem223(int x) { return FieldElement(x, 223); }

BOOST_AUTO_TEST_SUITE(PointTests)

namespace point {
BOOST_AUTO_TEST_CASE(valid_point) {
  int prime = 223;
  pair<int, int> points[] = {
      {192, 105},
      {17, 56},
      {1, 193},
  };
  FieldElement a(0, prime);
  FieldElement b(7, prime);
  for (auto p : points) {
    FieldElement x(p.first, prime);
    FieldElement y(p.second, prime);
    BOOST_CHECK_NO_THROW(Point(x, y, a, b));
  }
}

BOOST_AUTO_TEST_CASE(invalid_point) {
  int prime = 223;
  pair<int, int> points[] = {
      {200, 119},
      {42, 99},
  };
  FieldElement a(0, prime);
  FieldElement b(7, prime);
  for (auto &p : points) {
    FieldElement x(p.first, prime);
    FieldElement y(p.second, prime);
    BOOST_CHECK_THROW(Point(x, y, a, b), std::invalid_argument);
  }
}
// add points
BOOST_AUTO_TEST_CASE(add_points) {
  Point p1(elem223(192), elem223(105), elem223(0), elem223(7));
  Point p2(elem223(17), elem223(56), elem223(0), elem223(7));
  Point p3(elem223(170), elem223(142), elem223(0), elem223(7));
  BOOST_CHECK_EQUAL(p1 + p2, p3);
}

// // add point to infinity
BOOST_AUTO_TEST_CASE(add_point_to_infinity) {
  Point p1(elem223(192), elem223(105), elem223(0), elem223(7));
  BOOST_CHECK_EQUAL(p1 + INIFINITY_POINT, p1);
  BOOST_CHECK_EQUAL(INIFINITY_POINT + p1, p1);
}

// add point to self
BOOST_AUTO_TEST_CASE(add_point_to_self) {
  Point p1(elem223(192), elem223(105), elem223(0), elem223(7));
  Point p2(elem223(49), elem223(71), elem223(0), elem223(7));
  BOOST_CHECK_EQUAL(p1 + p1, p2);

  Point p3(elem223(47), elem223(71), elem223(0), elem223(7));
  Point p4(elem223(36), elem223(111), elem223(0), elem223(7));

  BOOST_CHECK_EQUAL(p3 + p3, p4);
}

BOOST_AUTO_TEST_CASE(mul) {
  Point p1(elem223(192), elem223(105), elem223(0), elem223(7));
  Point p2(elem223(49), elem223(71), elem223(0), elem223(7));
  BOOST_CHECK_EQUAL(2 * p1, p2);

  Point p3(elem223(143), elem223(98), elem223(0), elem223(7));
  Point p4(elem223(64), elem223(168), elem223(0), elem223(7));

  BOOST_CHECK_EQUAL(2 * p3, p4);

  Point p5(elem223(47), elem223(71), elem223(0), elem223(7));
  Point p6(elem223(194), elem223(51), elem223(0), elem223(7));

  BOOST_CHECK_EQUAL(4 * p5, p6);

  BOOST_CHECK_EQUAL(21 * p5, INIFINITY_POINT);
}
} // namespace point

BOOST_AUTO_TEST_SUITE_END();