
#include <boost/test/unit_test.hpp>
#include <private_key/private_key.h>
#include <util/int512.h>

using namespace std;

BOOST_AUTO_TEST_SUITE(PrivateKeyTests)

namespace private_key {
BOOST_AUTO_TEST_CASE(sign) {
  auto pk = PrivateKey(int512("0x8927a396c3c190d3d66231e90da99b0e42cec7c022763e95900b980feb763de4"));
  auto z = int512("0x7F9");
  auto signature = pk.sign(z);
  BOOST_CHECK(pk.point().verify(z, signature));
}
} // namespace private_key

BOOST_AUTO_TEST_SUITE_END()