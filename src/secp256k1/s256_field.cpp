#include <secp256k1/s256_field.h>

S256Field::S256Field(const uint256 &num) : FieldElement(num, P) {}