#ifndef PROGRAMMING_BITCOIN_SIGNATURE_H
#define PROGRAMMING_BITCOIN_SIGNATURE_H

#include <util/int512.h>

class Signature {
private:
  int512 r_;
  int512 s_;

public:
  Signature() = delete;
  Signature(const int512 &r, const int512 &s);
  int512 r() const { return r_; }
  int512 s() const { return s_; }
};

std::ostream &operator<<(std::ostream &os, const Signature &sig);

#endif // PROGRAMMING_BITCOIN_SIGNATURE_H