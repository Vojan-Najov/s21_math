#include <limits.h>

#include "s21_math.h"

long double s21_trunc(double num) {
  long double result;
  if (num >= LLONG_MAX || num <= LLONG_MIN || num != num || num == 0.0) {
    result = num;
  } else {
    long long n = (long long)num;
    long double d = (long double)n;
    result = d;
  }
  return result;
}
