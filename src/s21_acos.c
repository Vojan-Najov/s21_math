#include "s21_math.h"

long double s21_acos(double x) {
  long double res = 0.0;

  if (x == 1.0) {
    res = 0.0;
  } else if (x == -1.0) {
    res = S21_PI;
  } else if (x == 0.0) {
    res = (S21_PI / 2.0);
  } else {
    res = S21_PI / 2.0 - s21_asin(x);
  }

  return res;
}
