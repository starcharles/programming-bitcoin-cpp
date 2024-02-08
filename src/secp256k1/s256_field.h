#ifndef PROGRAMMING_BITCOIN_S256_FIELD_H
#define PROGRAMMING_BITCOIN_S256_FIELD_H

#include <field_element/field_element.h>
#include <util/int256.h>

using namespace std;

// P is the prime number 2**256 - 2**32 - 977
static const int256
    P("0xfffffffffffffffffffffffffffffffffffffffffffffffffffffffefffffc2f");

class S256Field : public FieldElement {
public:
  S256Field(const int256 &num);
};

std::ostream &operator<<(std::ostream &os, const S256Field &f);

#endif // PROGRAMMING_BITCOIN_S256_FIELD_H