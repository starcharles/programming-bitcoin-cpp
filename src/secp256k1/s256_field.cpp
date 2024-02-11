#include <secp256k1/s256_field.h>

S256Field::S256Field(const int512 &num) : FieldElement(num, P) {}

std::ostream &operator<<(std::ostream &os, const S256Field &f) {
  // hex
  os << "S256Field(" << std::hex << f.num() << ")";
  return os;
}