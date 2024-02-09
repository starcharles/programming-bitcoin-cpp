#include <signature/signature.h>

Signature::Signature(const int512 &r, const int512 &s) : r_(r), s_(s) {}

std::ostream &operator<<(std::ostream &os, const Signature &sig) {
  os << std::hex << "Signature(r=" << sig.r() << ", s=" << sig.s() << ")";
  return os;
}