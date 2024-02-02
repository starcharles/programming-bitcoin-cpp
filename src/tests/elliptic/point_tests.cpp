
#include <boost/test/included/unit_test.hpp>
#include <field_element.h>
#include <math.h>
#include <point.h>

#define BOOST_TEST_NO_MAIN

using namespace std;

BOOST_AUTO_TEST_SUITE(PointTests)
namespace point_test {
BOOST_AUTO_TEST_CASE(valid_point) {
  FieldElement x(170, 223);
  FieldElement y(142, 223);
  FieldElement a(1, 223);
  FieldElement b(7, 223);
  // y * y == x * x * x + a * x + b
  BOOST_CHECK_NO_THROW(Point(x, y, a, b));
  // BOOST_CHECK_NO_THROW(Point(18, 77, 5, 7));
  // BOOST_CHECK_NO_THROW(Point(MY_INFINITY, MY_INFINITY, 5, 7));
}

// BOOST_AUTO_TEST_CASE(invalid_point) {
//   BOOST_CHECK_THROW(Point(2, 4, 5, 7), invalid_argument);
//   BOOST_CHECK_THROW(Point(3, 6, 5, 7), invalid_argument);
// }
// // add points
// BOOST_AUTO_TEST_CASE(add_points) {
//   Point p1(2, 5, 5, 7);
//   Point p2(-1, -1, 5, 7);
//   Point p3(3, -7, 5, 7);
//   BOOST_CHECK_EQUAL(p1 + p2, p3);

//   Point p4(-1, -1, 5, 7);
//   Point p5(18, 77, 5, 7);
//   Point p6(-1, 1, 5, 7);
//   BOOST_CHECK_EQUAL(p4 + p5, p6);
// }

// // add point to infinity
// BOOST_AUTO_TEST_CASE(add_point_to_infinity) {
//   Point p1(2, 5, 5, 7);
//   Point p2(MY_INFINITY, MY_INFINITY, 5, 7);
//   BOOST_CHECK_EQUAL(p1 + p2, p1);

//   Point p3(2, 5, 5, 7);
//   Point p4(MY_INFINITY, MY_INFINITY, 5, 7);
//   BOOST_CHECK_EQUAL(p4 + p3, p3);
// }

// // add point to self
// BOOST_AUTO_TEST_CASE(add_point_to_self) {
//   Point p1(2, 5, 5, 7);
//   Point p2(2, 5, 5, 7);
//   cout << p1 + p2 << endl;
//   Point p3(60, 71, 5, 7);
//   BOOST_CHECK_EQUAL(p1 + p2, p3);

//   Point p4(3, 7, 5, 7);
//   Point p5(3, 7, 5, 7);
//   cout << p4 + p5 << endl;
//   Point p6(3, 7, 5, 7);
//   BOOST_CHECK_EQUAL(p4 + p5, p6);
// }

} // namespace point_test

BOOST_AUTO_TEST_SUITE_END()
