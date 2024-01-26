#include <boost/test/unit_test.hpp>
#include <point.h>

using namespace std;

BOOST_AUTO_TEST_SUITE(PointTests)
namespace point {
BOOST_AUTO_TEST_CASE(valid_point) {
  BOOST_CHECK_NO_THROW(Point(0, 1, 5, 7));
  BOOST_CHECK_NO_THROW(Point(INFINITY, INFINITY, 5, 7));
}

BOOST_AUTO_TEST_CASE(invalid_point) {
  BOOST_CHECK_THROW(Point(2, 4, 5, 7), invalid_argument);
  BOOST_CHECK_THROW(Point(3, 6, 5, 7), invalid_argument);
}
// add points
BOOST_AUTO_TEST_CASE(add_points) {
  // (2, 4) + (2, 4) = (5, 1)
  Point p1(2, 4, 5, 7);
  Point p2(2, 4, 5, 7);
  Point p3(5, 1, 5, 7);
  BOOST_CHECK_EQUAL(p1 + p2, p3);

  // (2, 4) + (-1, -1) = (3, -7)
  Point p4(2, 4, 5, 7);
  Point p5(-1, -1, 5, 7);
  Point p6(3, -7, 5, 7);
  BOOST_CHECK_EQUAL(p4 + p5, p6);

  // (3, 7) + (18, 77) = (2, 5)
  Point p7(3, 7, 5, 7);
  Point p8(18, 77, 5, 7);
  Point p9(2, 5, 5, 7);
  BOOST_CHECK_EQUAL(p7 + p8, p9);
}

// add point to infinity
BOOST_AUTO_TEST_CASE(add_point_to_infinity) {
  // (2, 4) + O = (2, 4)
  Point p1(2, 4, 5, 7);
  Point p2(INFINITY, INFINITY, 5, 7);
  BOOST_CHECK_EQUAL(p1 + p2, p1);

  // (2, 4) + O = (2, 4)
  Point p3(2, 4, 5, 7);
  Point p4(INFINITY, INFINITY, 5, 7);
  BOOST_CHECK_EQUAL(p4 + p3, p3);
}
// add point to self
BOOST_AUTO_TEST_CASE(add_point_to_self) {
  // (2, 4) + 2 = (5, 1)
  Point p1(2, 4, 5, 7);
  Point p2(2, 4, 5, 7);
  Point p3(5, 1, 5, 7);
  BOOST_CHECK_EQUAL(p1 + p2, p3);

  // (2, 4) + 2 = (5, 1)
  Point p4(2, 4, 5, 7);
  Point p5(2, 4, 5, 7);
  Point p6(5, 1, 5, 7);
  BOOST_CHECK_EQUAL(p4 + p5, p6);
}

} // namespace point

BOOST_AUTO_TEST_SUITE_END()