
#include <boost/test/unit_test.hpp>
#include <secp256k1/s256_point.h>
#include <util/int512.h>

using namespace std;

BOOST_AUTO_TEST_SUITE(S256PointTests)

namespace s256_point {
BOOST_AUTO_TEST_CASE(infinity) {

  auto G = S256Point(
      S256Field(int512("0x79be667ef9dcbbac55a06295ce870b07029bfcdb2dce28d959f28"
                       "15b16f81798")),
      S256Field(int512(
          "0x483ada7726a3c4655da4fbfc0e1108a8fd17b448a68554199c47d08ffb10"
          "d4b8")));

  auto n = int512(
      "0xfffffffffffffffffffffffffffffffebaaedce6af48a03bbfd25e8cd0364141");

  BOOST_CHECK_EQUAL(n * G, S256Point::INIFINITY_POINT);
}

} // namespace s256_point

BOOST_AUTO_TEST_SUITE_END()