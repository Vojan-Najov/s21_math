#include "s21_math.h"

long double s21_exp(double x) {
  long double num = x;
  long double result = 0.0;
  long double a;
  long double n;

  if (s21_isnan(x)) {
    result = x;
  } else if (x >= 1024.0) {
    result = S21_INFINITY;
  } else if (x >= -16.0) {
    a = 1.0;
    n = 0.0;
    while (a > 1.0e-16L || a < -1.0e-16L) {
      result += a;
      n += 1.0;
      a *= num / n;
    }
  }

  return ((double)result);
}

/* good version, but does not match exactly */
/*
#include <stdint.h>
long double s21_exp(double x) {
        double result;
        double a;
        double n;
        double r;
        double dk;
        int k = 0;

        if (x != x) {
                result = x;
        } else {
                r = fmod(x, S21_LN2); // replace on s21_fmod
                dk = (x - r) / S21_LN2;
                dk = s21_ceil(dk);
                if (dk > (double) 0x7FF) {
                        result = 1.0 / 0.0;
                } else {
                        a = 1.0;
                        n = 0.0;
                        result = 0.0;
                        x = r;
                        k = (int) dk;
                        while (s21_fabs(a) > 1e-16) {
                                result += a;
                                n += 1.0;
                                a *= x / n;
                        }
                        union {
                                double num;
                                struct {
                                        uint64_t mant : 52;
                                        uint64_t exp : 11;
                                        uint64_t sign : 1;
                                } bits;
                        } un = {result};
                        int exp = un.bits.exp;
                        exp += k;
                        if (exp > 0x7ff ) {
                                result = 1.0 / 0.0;
                        } else if (exp <= 0) {
                                result = 0.0;
                        } else {
                                un.bits.exp = (uint64_t) exp;
                                result = un.num;
                        }
                }
        }

        return (result);
}
*/
