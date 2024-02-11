#include <boost/multiprecision/cpp_int.hpp>
#include <boost/random.hpp>
#include <boost/random/random_device.hpp>
#include <consts/math.cpp>
#include <private_key/private_key.h>
#include <util/math.h>

PrivateKey::PrivateKey(const int512 &secret)
    : secret_(secret), point_(secret * G) {}

Signature PrivateKey::sign(const int512 &z) const {
  boost::random::random_device rd;
  boost::random::mt19937 gen(rd());
  boost::multiprecision::cpp_int upper_limit =
      boost::multiprecision::pow(boost::multiprecision::cpp_int(2), 256) - 1;
  boost::random::uniform_int_distribution<boost::multiprecision::cpp_int> dist(
      0, upper_limit);
  auto random_number = dist(gen);
  int512 k = random_number.convert_to<boost::multiprecision::int512_t>();

  auto r = (k * G).x().num();
  auto k_inv = math::my_pow(k, N - 2, N);
  auto s = ((z + r * secret_) * k_inv) % N;
  if (s > (N / 2)) {
    s = N - s;
  }
  return Signature(r, s);
}

std::ostream &operator<<(std::ostream &os, const PrivateKey &pk) {
  os << std::hex << "PrivateKey(" << pk.secret() << ")";
  return os;
}