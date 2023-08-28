#include <errno.h>

#include "s21_math.h"

long double s21_log(double x) {
  double result = 0.0;
  double z = x;
  double t = 1.0;
  double eps = 1.0e-16;

  if (s21_isnan(x)) {
    errno = EDOM;
    result = x;
  } else if (x < 0.0) {
    errno = EDOM;
    result = -S21_NAN;
  } else if (s21_isinf(x)) {
    result = x;
  } else if (x == 0.0) {
    errno = ERANGE;
    result = -1.0 / 0.0;
  } else {
    /* INVARIANT: e^result * z^t = x */
    /* BEGIN: result = 0, z = x, t = 1.0. END: z^t == 1.0 => e^result == y */
    while (z < 1.0 / S21_E || z > S21_E || t < -eps || t > eps) {
      if (z < 1.0 / S21_E) {
        z *= S21_E;
        result -= t;
      } else if (z > S21_E) {
        z /= S21_E;
        result += t;
      } else {
        t /= 2.0;
        z *= z;
      }
    }
  }

  return (result);
}

/* low accuracy implementation with taylor series expansion */
/*
#include <stdint.h>
long double s21_log(double x) {
        long double result;
        long double a;
        long double n;
        union {
                double num;
                struct {
                        uint64_t mant : S21_DBL_MANT_BITS_COUNT;
                        uint64_t exp : S21_DBL_EXP_BITS_COUNT;
                        uint64_t sign : 1;
                } bits;
        } un = {x};
        long double exp = (long double)((int)un.bits.exp - S21_DBL_EXP_OFFSET);
        int sign = un.bits.sign;
        un.bits.exp = 0x3FF;
        long double mant = (long double) (un.num - 1.0);

        if (sign) {
                errno = EDOM;
                result = 0.0 / 0.0;
        } else if (x == 0.0) {
                errno = ERANGE;
                result = - 1.0 / 0.0;
        } else {
                result = 0.0;
                a = mant;
                n = 1.0;
                while (a > 1.0e-16L || a < -1.0e-16L) {
                        result += a;
                        n += 1.0;
                        mant *= -mant;
                        a = mant/n;
                }
                result += exp * (long double) S21_LN2;
        }

        return (result);
}
*/
