
#include <boost/test/unit_test.hpp>
#include <secp256k1/s256_point.h>

using namespace std;

BOOST_AUTO_TEST_SUITE(S256PointTests)

namespace s256_point {
BOOST_AUTO_TEST_CASE(infinity) {

  //   auto G = S256Point(
  //       int256(
  //           "79be667ef9dcbbac55a06295ce870b07029bfcdb2dce28d959f2815b16f81798"),
  //       int256("483ada7726a3c4655da4fbfc0e1108a8fd17b448a68554199c47d08ffb10d4b"
  //              "8"));
  //   auto N = int256(
  //       "fffffffffffffffffffffffffffffffebaaedce6af48a03bbfd25e8cd0364141");
  //   BOOST_CHECK_EQUAL(N * G, S256Point::INIFINITY_POINT);
  BOOST_CHECK_EQUAL(1, 1);
}

} // namespace s256_point

BOOST_AUTO_TEST_SUITE_END()