#include <stdint.h>

#include "s21_math.h"

static double toint = 4503599627370496.0; /* 2^52 */

long double s21_ceil(double x) {
  double result;
  double fractpart;
  union {
    double num;
    struct {
      uint64_t mantissa : S21_DBL_MANT_BITS_COUNT;
      uint64_t exp : S21_DBL_EXP_BITS_COUNT;
      uint64_t sign : 1;
    } bits;
  } un = {x};
  int sign = un.bits.sign;
  int exp = (int)un.bits.exp - S21_DBL_EXP_OFFSET;

  if (exp > S21_DBL_MANT_BITS_COUNT || x == 0.0) {
    result = x;
  } else if (exp < 0) {
    result = sign ? -0.0 : 1.0;
  } else {
    if (sign) {
      fractpart = ((x - toint) + toint) - x; /* x < 0 && fractpart > 0 */
    } else {
      fractpart = ((x + toint) - toint) - x; /* x > 0 && fractpart < 0 */
    }
    if (fractpart < 0.0) {
      /* x > 0 */
      result = x + fractpart + 1;
    } else {
      /* x < 0 */
      result = x + fractpart;
    }
  }

  return (result);
}
