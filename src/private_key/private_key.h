#ifndef PROGRAMMING_BITCOIN_PRIVATE_KEY_H
#define PROGRAMMING_BITCOIN_PRIVATE_KEY_H

#include <secp256k1/s256_point.h>
#include <signature/signature.h>
#include <util/int512.h>

class PrivateKey {
private:
  int512 secret_;
  S256Point point_;

public:
  PrivateKey() = delete;
  PrivateKey(const int512 &secret);
  int512 secret() const { return secret_; }
  S256Point point() const { return point_; }
  Signature sign(const int512 &z) const;
};

std::ostream &operator<<(std::ostream &os, const PrivateKey &pk);

#endif // PROGRAMMING_BITCOIN_PRIVATE_KEY_H