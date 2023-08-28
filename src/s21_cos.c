#include "s21_math.h"

long double s21_cos(double x) {
  double result;
  double k;
  double a;
  double eps = 1.0e-16;

  if (s21_isnan(x)) {
    result = x;
  } else if (s21_isinf(x)) {
    result = -S21_NAN;
  } else {
    x = s21_fmod(x, 2.0 * S21_PI);
    if (x > S21_PI) {
      x -= 2.0 * S21_PI;
    } else if (x < -S21_PI) {
      x += 2.0 * S21_PI;
    }
    a = 1.0;
    k = 1.0;
    result = 0.0;
    while (s21_fabs(a) > eps) {
      result += a;
      a = ((-a) * x * x) / ((k) * (k + 1.0));
      k += 2.0;
    }
  }

  return (result);
}
