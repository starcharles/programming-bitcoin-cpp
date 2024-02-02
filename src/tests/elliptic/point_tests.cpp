
#include <boost/test/included/unit_test.hpp>
#include <point.h>

using namespace std;

FieldElement elem(int x) { return FieldElement(x, 223); }

BOOST_AUTO_TEST_SUITE(PointTests)

namespace point_test {
BOOST_AUTO_TEST_CASE(valid_point) {
  FieldElement x(170, 223);
  FieldElement y(142, 223);
  FieldElement a(1, 223);
  FieldElement b(7, 223);
  // y * y == x * x * x + a * x + b
  BOOST_CHECK_NO_THROW(Point(x, y, a, b));
}

BOOST_AUTO_TEST_CASE(invalid_point) {
  FieldElement x1(2, 223);
  FieldElement y1(4, 223);
  FieldElement a1(5, 223);
  FieldElement b1(7, 223);
  BOOST_CHECK_THROW(Point(x1, y1, a1, b1), std::invalid_argument);
}
// add points
BOOST_AUTO_TEST_CASE(add_points) {
  Point p1(elem(2), elem(5), elem(5), elem(7));
  Point p2(elem(-1), elem(-1), elem(5), elem(7));
  Point p3(elem(3), elem(-7), elem(5), elem(7));
  BOOST_CHECK_EQUAL(p1 + p2, p3);
}

// // add point to infinity
BOOST_AUTO_TEST_CASE(add_point_to_infinity) {
  // Point p1(2, 5, 5, 7);
  // Point p2(MY_INFINITY, MY_INFINITY, 5, 7);
  // BOOST_CHECK_EQUAL(p1 + p2, p1);

  // Point p3(2, 5, 5, 7);
  // Point p4(MY_INFINITY, MY_INFINITY, 5, 7);
  // BOOST_CHECK_EQUAL(p4 + p3, p3);
}

// add point to self
BOOST_AUTO_TEST_CASE(add_point_to_self) {
  // Point p1(2, 5, 5, 7);
  // Point p2(2, 5, 5, 7);
  // cout << p1 + p2 << endl;
  // Point p3(60, 71, 5, 7);
  // BOOST_CHECK_EQUAL(p1 + p2, p3);

  // Point p4(3, 7, 5, 7);
  // Point p5(3, 7, 5, 7);
  // cout << p4 + p5 << endl;
  // Point p6(3, 7, 5, 7);
  // BOOST_CHECK_EQUAL(p4 + p5, p6);
}

} // namespace point_test

BOOST_AUTO_TEST_SUITE_END()