#include <stdint.h>

#include "s21_math.h"

int s21_isinf(double x) {
  union {
    double x;
    uint64_t ix;
  } un = {x};

  return (x == x && (((un.ix) << 1 >> 53) == 0x7FF));
}
