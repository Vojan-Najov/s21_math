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
