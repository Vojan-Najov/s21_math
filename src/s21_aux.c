#include <stdint.h>

#include "s21_math.h"

int s21_isnan(double x) { return (x != x); }

int s21_isinf(double x) {
  union {
    double x;
    uint64_t ix;
  } un = {x};

  return (x == x && (((un.ix) << 1 >> 53) == 0x7FF));
}

float _s21_nan(void) {
  union {
    float x;
    unsigned int ix;
  } un;

  un.ix = (0xFF << 23) | (1 << 22);

  return (un.x);
}

float _s21_inf(void) {
  union {
    float x;
    unsigned int ix;
  } un;

  un.ix = (0xFF << 23);

  return (un.x);
}

long double _s21_integer_pow(double base, double e) {
  long double k;
  long double b;
  long double result;

  k = s21_trunc(e);
  b = base;
  result = 1.0;
  /* INVARIANT: b^k * result = base^e */
  while (s21_fabs(k) > 0.1) {
    if (k > 0.0) {
      if (s21_fabs(s21_fmod(k, 2.0)) < 0.1) {
        b *= b;
        k /= 2.0;
      } else {
        k -= 1.0;
        result *= b;
      }
    } else {
      if (s21_fabs(s21_fmod(k, 2.0)) < 0.1) {
        b *= b;
        k /= 2.0;
      } else {
        k += 1.0;
        result /= b;
      }
    }
  }

  return ((double)result);
}
