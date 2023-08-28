#include <stdint.h>

#include "s21_math.h"

long double s21_asin(double x) {
  long double result = 0;
  int sign = 0;

  if (x != x) {
    result = x;
  } else if (x == 0) {
    result = x;
  } else if (s21_fabs(x) > 1.0) {
    result = S21_NAN;
  } else {
    union {
      double num;
      struct double_bits {
        uint64_t mantissa : S21_DBL_MANT_BITS_COUNT;
        uint64_t exp : S21_DBL_EXP_BITS_COUNT;
        uint64_t sign : 1;
      } bits;
    } un = {x};
    sign = un.bits.sign;
    x = (sign) ? s21_fabs(x) : x;
    if (x == 1.0) {
      result = S21_PI / 2.0;
    } else if (x == 1.0 / 2.0) {
      result = S21_PI / 6.0;
    } else {
      result = 0.0;
      long double n = 0.0;
      long double add = x;
      while (s21_fabs(add) > S21_EPS) {
        result += add;
        n++;
        add *= ((2.0 * n - 1.0) * (2.0 * n - 1.0) * x * x) /
               (2.0 * n * (2.0 * n + 1.0));
      }
    }
  }
  return (sign) ? -result : result;
}
