#include <boost/test/unit_test.hpp>
#include <field_element/field_element.h>
#include <util/int512.h>

using namespace std;

BOOST_AUTO_TEST_SUITE(FieldElementTests)

namespace field_element {
BOOST_AUTO_TEST_CASE(equal_and_not_equal) {
  const FieldElement f1(1, 7);
  const FieldElement f2(2, 7);
  BOOST_CHECK(f1 == f1);
  BOOST_CHECK(f1 != f2);
}

BOOST_AUTO_TEST_CASE(add) {
  {
    const FieldElement f1(1, 7);
    const FieldElement f2(2, 7);
    const FieldElement f3(3, 7);

    BOOST_CHECK_EQUAL(f1 + f2, f3);
  }

  {
    const FieldElement f1(6, 7);
    const FieldElement f2(4, 7);
    const FieldElement f3(3, 7);

    BOOST_CHECK_EQUAL(f1 + f2, f3);
  }
}

BOOST_AUTO_TEST_CASE(sub) {
  {
    const FieldElement f1(1, 7);
    const FieldElement f2(2, 7);
    const FieldElement f3(6, 7);

    BOOST_CHECK_EQUAL(f1 - f2, f3);
  }

  {
    const FieldElement f1(6, 7);
    const FieldElement f2(4, 7);
    const FieldElement f3(2, 7);

    BOOST_CHECK_EQUAL(f1 - f2, f3);
  }
}

BOOST_AUTO_TEST_CASE(mul) {
  {
    const FieldElement f1(1, 7);
    const FieldElement f2(2, 7);
    const FieldElement f3(2, 7);

    BOOST_CHECK_EQUAL(f1 * f2, f3);
  }

  {
    const FieldElement f1(6, 7);
    const FieldElement f2(4, 7);
    const FieldElement f3(3, 7);

    BOOST_CHECK_EQUAL(f1 * f2, f3);
  }
  {
    const FieldElement f1(2, 7);
    const FieldElement f2(6, 7);

    BOOST_CHECK_EQUAL(f1 * 3, f2);
    BOOST_CHECK_EQUAL(3 * f1, f2);
  }
}
BOOST_AUTO_TEST_CASE(div) {
  {
    const FieldElement f1(3, 31);
    const FieldElement f2(24, 31);
    const FieldElement f3(4, 31);

    BOOST_CHECK_EQUAL(f1 / f2, f3);
  }
  {
    const FieldElement f1(17, 31);

    BOOST_CHECK_EQUAL(f1 ^ (-3), FieldElement(29, 31));
  }
  {
    const FieldElement f1(4, 31);
    const FieldElement f2(11, 31);

    BOOST_CHECK_EQUAL((f1 ^ (-4)) * f2, FieldElement(13, 31));
  }
}
} // namespace field_element

BOOST_AUTO_TEST_SUITE_END()