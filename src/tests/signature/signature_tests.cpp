
#include <boost/test/unit_test.hpp>
#include <secp256k1/s256_field.h>
#include <secp256k1/s256_point.h>
#include <util/int512.h>

using namespace std;

BOOST_AUTO_TEST_SUITE(SignatureTests)

namespace signature {
BOOST_AUTO_TEST_CASE(verify) {

  auto point = S256Point(
      S256Field(int512("0x887387e452b8eacc4acfde10d9aaf7f6d9a0f975aabb1"
                       "0d006e4da568744d06c")),
      S256Field(int512("0x61de6d95231cd89026e286df3b6ae4a894a3378e393e9"
                       "3a0f45b666329a0ae34")));
  auto z = int512(
      "0xec208baa0fc1c19f708a9ca96fdeff3ac3f230bb4a7ba4aede4942ad003c0f60");
  auto r = int512(
      "0xac8d1c87e51d0d441be8b3dd5b05c8795b48875dffe00b7ffcfac23010d3a395");
  auto s = int512(
      "0x68342ceff8935ededd102dd876ffd6ba72d6a427a3edb13d26eb0781cb423c4");
  BOOST_CHECK(point.verify(z, Signature(r, s)));

  z = int512(
      "0x7c076ff316692a3d7eb3c3bb0f8b1488cf72e1afcd929e29307032997a838a3d");
  r = int512(
      "0xeff69ef2b1bd93a66ed5219add4fb51e11a840f404876325a1e8ffe0529a2c");
  s = int512(
      "0xc7207fee197d27c618aea621406f6bf5ef6fca38681d82b2f06fddbdce6feab6");
  BOOST_CHECK(point.verify(z, Signature(r, s)));
}
} // namespace signature

BOOST_AUTO_TEST_SUITE_END()