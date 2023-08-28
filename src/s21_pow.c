#include "s21_math.h"

long double s21_pow(double base, double e) {
  long double result;
  long double fractpart;
  long double eps = 1.0e-16;

  if (e == 0.0) {
    result = 1.0;
  } else if (s21_isnan(base)) {
    if (s21_fabs(s21_fabs(e) - 1.0) < eps) {
      result = S21_NAN;
    } else {
      result = base;
    }
  } else if (s21_fabs(e - 1.0) < eps) {
    result = base;
  } else if (s21_fabs(e + 1.0) < eps) {
    result = 1.0 / base;
  } else if (s21_isnan(e)) {
    if (s21_fabs(base - 1.0) < eps) {
      result = 1.0;
    } else {
      result = e;
    }
  } else if (s21_isinf(base)) {
    if (s21_isinf(e)) {
      if (e > 0.0) {
        result = S21_INFINITY;
      } else {
        result = 0.0;
      }
    } else if (e < 0.0) {
      if (s21_fabs(s21_trunc(e) - e) < eps) {
        result = base > 0.0 ? 0.0 : -0.0;
      } else {
        result = 0.0;
      }
    } else if (s21_fabs(s21_fmod(e, 2.0) - 1.0) < eps) {
      result = base;
    } else {
      result = S21_INFINITY;
    }
  } else if (s21_isinf(e)) {
    if (s21_fabs(s21_fabs(base) - 1.0) < eps) {
      result = 1.0;
    } else if (s21_fabs(base) < eps) {
      result = e > 0.0 ? 0.0 : S21_INFINITY;
    } else if (s21_fabs(base) < 1.0) {
      result = e > 0.0 ? 0.0 : S21_INFINITY;
    } else {
      result = e > 0.0 ? S21_INFINITY : 0.0;
    }
  } else if (s21_fabs(base) < eps) {
    if (e < 0.0) {
      result = S21_INFINITY;
    } else {
      result = 0.0;
    }
  } else if (base < 0) {
    fractpart = s21_trunc(e) - e;
    if (s21_fabs(fractpart) > S21_EPS)
      result = -S21_NAN;
    else {
      result = _s21_integer_pow(base, e);
    }
  } else {
    fractpart = e - s21_trunc(e);
    result = _s21_integer_pow(base, e);
    if (s21_fabs(fractpart) > eps) {
      result *= s21_exp(fractpart * s21_log(base));
    }
  }

  return (result);
}
