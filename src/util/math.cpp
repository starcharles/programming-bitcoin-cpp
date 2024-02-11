#include <util/math.h>

// int512 math::my_pow(int512 base, int512 exp, int512 mod) {
//   int512 result = 1;
//   for (int512 i = 0; i < exp; i += 1) {
//     result *= base;
//     result %= mod;
//   }
//   return result;
// }

int512 math::my_pow(int512 base, int512 exp, int512 mod) {
  int512 result = 1;
  base %= mod;
  while (exp > 0) {
    if (exp % 2 == 1) {
      result = (result * base) % mod;
    }
    base = (base * base) % mod;
    exp = exp / 2;
  }
  return result;
}