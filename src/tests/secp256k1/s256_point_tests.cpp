
#include <boost/test/unit_test.hpp>
#include <secp256k1/s256_point.h>
#include <util/int256.h>

using namespace std;

BOOST_AUTO_TEST_SUITE(S256PointTests)

namespace s256_point {
BOOST_AUTO_TEST_CASE(infinity) {

  // auto G =
  // S256Point(int256("55066263022277343669578718895168534326250603453777"
  //                           "594175500187360389116729240"),
  //                    int256("32670510020758816978083085130507043184471273380659"
  //                           "243275938904335757337482424"));
  auto G = S256Point(
      int256(
          "0x79be667ef9dcbbac55a06295ce870b07029bfcdb2dce28d959f2815b16f81798"),
      int256("0x483ada7726a3c4655da4fbfc0e1108a8fd17b448a68554199c47d08ffb10d4b"
             "8"));

  auto n = int256(
      "0xfffffffffffffffffffffffffffffffebaaedce6af48a03bbfd25e8cd0364141");
  // auto n =
  //     int256("115792089237316195423570985008687907852837564279074904382605");

  BOOST_CHECK_EQUAL(n * G, S256Point::INIFINITY_POINT);
}

} // namespace s256_point

BOOST_AUTO_TEST_SUITE_END()