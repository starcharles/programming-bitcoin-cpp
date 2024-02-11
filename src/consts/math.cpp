#include <secp256k1/s256_field.h>
#include <secp256k1/s256_point.h>
#include <util/int512.h>

static const auto G = S256Point(
    S256Field(int512("0x79be667ef9dcbbac55a06295ce870b07029bfcdb2dce28d959f28"
                     "15b16f81798")),
    S256Field(
        int512("0x483ada7726a3c4655da4fbfc0e1108a8fd17b448a68554199c47d08ffb10"
               "d4b8")));