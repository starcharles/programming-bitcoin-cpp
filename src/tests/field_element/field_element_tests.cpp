#define BOOST_TEST_MODULE FieldElement
#include <boost/test/included/unit_test.hpp>
#include <field_element.h>

using namespace std;

namespace field_element {
BOOST_AUTO_TEST_CASE(equal_and_not_equal) {
  const FieldElement f1(1, 7);
  const FieldElement f2(2, 7);
  BOOST_CHECK(f1 == f1);
  BOOST_CHECK(f1 != f2);
}

BOOST_AUTO_TEST_CASE(plus) {
  {
    const FieldElement f1(1, 7);
    const FieldElement f2(2, 7);
    const FieldElement f3(3, 7);

    BOOST_CHECK_EQUAL(f1 + f2, f3);
    cout << f3 << endl;
  }

  {
    const FieldElement f1(6, 7);
    const FieldElement f2(4, 7);
    const FieldElement f3(3, 7);

    BOOST_CHECK_EQUAL(f1 + f2, f3);
    cout << f3 << endl;
  }
}
} // namespace field_element