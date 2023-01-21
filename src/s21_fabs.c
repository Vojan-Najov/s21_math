#include <stdint.h>

#include "s21_math.h"

double s21_fabs(double x) {
  union {
    double num;
    struct double_bits {
      uint64_t mant : S21_DBL_MANT_BITS_COUNT;
      uint64_t exp : S21_DBL_EXP_BITS_COUNT;
      uint64_t sign : 1;
    } bits;
  } un = {x};

  un.bits.sign = 0;

  return (un.num);
}
