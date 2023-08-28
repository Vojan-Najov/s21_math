#include "s21_math.h"

long double s21_atan(double x) {
  long double res = 0.0;
  double sign = 1.0;

  if (x != x)
    res = x;
  else if (x == S21_INFINITY)
    res = S21_PI / 2;
  else if (x == -S21_INFINITY)
    res = -S21_PI / 2;
  else if (x == 0)
    res = x;
  else if (x == -1)
    res = -(S21_PI / 4.);
  else if (x == 1)
    res = (S21_PI / 4.);
  else if (s21_fabs(x) < 1.) {
    res = s21_asin(x / (s21_sqrt(1 + (x * x))));
  } else {
    for (int i = 0; i < 500; i++) {
      res += (sign * s21_pow(x, -1 - (2 * i))) / (1 + 2 * i);
      sign = -sign;
    }
    res = S21_PI * s21_fabs(x) / (2 * x) - res;
  }

  return res;
}
