#include <stdint.h>

#include "s21_math.h"

long double s21_fmod(double x, double y) {
  double result;
  union {
    double num;
    struct {
      uint64_t mant : S21_DBL_MANT_BITS_COUNT;
      uint64_t exp : S21_DBL_EXP_BITS_COUNT;
    } bits;
  } ux = {x}, uy = {y};
  uint64_t xm, ym, dm;
  int ex = (int)ux.bits.exp;
  int ey = (int)uy.bits.exp;

  if (y == 0.0 || y != y || ex == 0x7FF) {
    result = (x * y) / (x * y);
  } else if (ex < ey || (ex == ey && ux.bits.mant <= uy.bits.mant)) {
    if (ex == ey && ux.bits.mant == uy.bits.mant) {
      result = 0.0 * x;
    } else {
      result = x;
    }
  } else {
    xm = ux.bits.mant | (1L << 52);
    ym = uy.bits.mant | (1L << 52);
    while (ex > ey) {
      dm = xm - ym;
      if (dm >> 63 == 0) {
        /* xm >= ym */
        if (dm == 0) {
          /* xm == ym */
          return (0.0 * x);
        }
        xm = dm;
      }
      xm <<= 1;
      --ex;
    }
    dm = xm - ym;
    if (dm >> 63 == 0) {
      if (dm == 0) {
        return (0.0 * x);
      }
      xm = dm;
    }
    while (xm >> 52 == 0) {
      xm <<= 1;
      --ex;
    }
    xm &= 0xFFFFFFFFFFFFF;
    ux.bits.exp = (uint64_t)ex;
    ux.bits.mant = xm;
    result = ux.num;
  }

  return (result);
}
