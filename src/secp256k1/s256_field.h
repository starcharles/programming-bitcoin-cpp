#ifndef PROGRAMMING_BITCOIN_S256_FIELD_H
#define PROGRAMMING_BITCOIN_S256_FIELD_H

#include <field_element/field_element.h>
#include <util/int256.h>

// P is the prime number 2**256 - 2**32 - 977
#define P                                                                      \
  int256("1157920892373161954235709850086879078532699846656405640394575840079" \
         "08834671663")

class S256Field : public FieldElement {
public:
  S256Field() = delete;
  S256Field(const int256 &num);
};

std::ostream &operator<<(std::ostream &os, const S256Field &f);

#endif // PROGRAMMING_BITCOIN_S256_FIELD_H