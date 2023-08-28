#include <check.h>
#include <float.h>
#include <math.h>
#include <stdio.h>

#include "s21_math.h"

START_TEST(e_zero) {
  double e;
  long double ret, ret21;
  double base[] = {
      0.0,           -0.0,       -1.0,      1.0,        -FLT_MIN,
      -FLT_MIN,      -2.0,       2,         0,          nan(""),
      -nan(""),      INFINITY,   -INFINITY, DBL_MAX,    -DBL_MAX,
      -100.0,        -101.0,     100.0,     101.0,      -100.5,
      -101.5,        100.5,      101.5,     -100.33333, -101.33333333,
      100.333333333, 101.3333333};

  e = 0.0;
  for (size_t i = 0; i < sizeof(base) / sizeof(double); ++i) {
    double b = base[i];
    ret = pow(b, e);
    ret21 = s21_pow(b, e);
    ck_assert_ldouble_eq(ret, ret21);
  }

  e = -0.0;
  for (size_t i = 0; i < sizeof(base) / sizeof(double); ++i) {
    double b = base[i];
    ret = pow(b, e);
    ret21 = s21_pow(b, e);
    ck_assert_ldouble_eq(ret, ret21);
  }
}
END_TEST

START_TEST(e_one) {
  double e;
  long double ret, ret21;
  double base[] = {
      0.0,           -0.0,       -1.0,      1.0,        -FLT_MIN,
      -FLT_MIN,      -2.0,       2,         0,          nan(""),
      -nan(""),      INFINITY,   -INFINITY, DBL_MAX,    -DBL_MAX,
      -100.0,        -101.0,     100.0,     101.0,      -100.5,
      -101.5,        100.5,      101.5,     -100.33333, -101.33333333,
      100.333333333, 101.3333333};

  e = 1.0;
  for (size_t i = 0; i < sizeof(base) / sizeof(double); ++i) {
    double b = base[i];
    ret = pow(b, e);
    ret21 = s21_pow(b, e);
    if (s21_isnan(ret)) {
      ck_assert_ldouble_nan(ret);
      ck_assert_ldouble_nan(ret21);
    } else {
      ck_assert_ldouble_eq(ret, ret21);
    }
  }

  e = -1.0;
  for (size_t i = 0; i < sizeof(base) / sizeof(double); ++i) {
    double b = base[i];
    ret = pow(b, e);
    ret21 = s21_pow(b, e);
    if (s21_isnan(ret)) {
      ck_assert_ldouble_nan(ret);
      ck_assert_ldouble_nan(ret21);
    } else {
      ck_assert_ldouble_eq(ret, ret21);
    }
  }
}
END_TEST

START_TEST(base_is_nan) {
  double base;
  long double ret, ret21;
  double e[] = {0.0,           -0.0,          -1.0,       1.0,       -FLT_MIN,
                -FLT_MIN,      -2.0,          2.0,        -2.50,     2.5,
                nan(""),       -nan(""),      INFINITY,   -INFINITY, DBL_MAX,
                -DBL_MAX,      -100.0,        -101.0,     100.0,     101.0,
                -100.5,        -101.5,        100.5,      101.5,     -100.33333,
                -101.33333333, 100.333333333, 101.3333333};

  base = nan("");
  for (size_t i = 0; i < sizeof(e) / sizeof(double); ++i) {
    ret = pow(base, e[i]);
    ret21 = s21_pow(base, e[i]);
    if (s21_isnan(ret)) {
      ck_assert_ldouble_nan(ret);
      ck_assert_ldouble_nan(ret21);
    } else {
      ck_assert_ldouble_eq(ret, ret21);
    }
  }

  base = -nan("");
  for (size_t i = 0; i < sizeof(e) / sizeof(double); ++i) {
    ret = pow(base, e[i]);
    ret21 = s21_pow(base, e[i]);
    if (s21_isnan(ret)) {
      ck_assert_ldouble_nan(ret);
      ck_assert_ldouble_nan(ret21);
    } else {
      ck_assert_ldouble_eq(ret, ret21);
    }
  }
}
END_TEST

START_TEST(base_is_inf) {
  double base;
  long double ret, ret21;
  double e[] = {0.0,           -0.0,       -1.0,      1.0,        -FLT_MIN,
                -FLT_MIN,      -2.0,       2,         0,          nan(""),
                -nan(""),      INFINITY,   -INFINITY, DBL_MAX,    -DBL_MAX,
                -100.0,        -101.0,     100.0,     101.0,      -100.5,
                -101.5,        100.5,      101.5,     -100.33333, -101.33333333,
                100.333333333, 101.3333333};

  base = INFINITY;
  for (size_t i = 0; i < sizeof(e) / sizeof(double); ++i) {
    ret = pow(base, e[i]);
    ret21 = s21_pow(base, e[i]);
    if (s21_isnan(ret)) {
      ck_assert_ldouble_nan(ret);
      ck_assert_ldouble_nan(ret21);
    } else {
      ck_assert_ldouble_eq(ret, ret21);
    }
  }

  base = -INFINITY;
  for (size_t i = 0; i < sizeof(e) / sizeof(double); ++i) {
    ret = pow(base, e[i]);
    ret21 = s21_pow(base, e[i]);
    if (s21_isnan(ret)) {
      ck_assert_ldouble_nan(ret);
      ck_assert_ldouble_nan(ret21);
    } else {
      ck_assert_ldouble_eq(ret, ret21);
    }
  }
}
END_TEST

START_TEST(e_is_inf) {
  double e;
  long double ret, ret21;
  double base[] = {
      0.0,           -0.0,        -1.0,      1.0,        -FLT_MIN,
      -FLT_MIN,      -2.0,        2,         0,          nan(""),
      -nan(""),      INFINITY,    -INFINITY, DBL_MAX,    -DBL_MAX,
      -100.0,        -101.0,      100.0,     101.0,      -100.5,
      -101.5,        100.5,       101.5,     -100.33333, -101.33333333,
      100.333333333, 101.3333333, 0.5,       -0,         5};

  e = INFINITY;
  for (size_t i = 0; i < sizeof(base) / sizeof(double); ++i) {
    double b = base[i];
    ret = pow(b, e);
    ret21 = s21_pow(b, e);
    if (s21_isnan(ret)) {
      ck_assert_ldouble_nan(ret);
      ck_assert_ldouble_nan(ret21);
    } else {
      ck_assert_ldouble_eq(ret, ret21);
    }
  }

  e = -INFINITY;
  for (size_t i = 0; i < sizeof(base) / sizeof(double); ++i) {
    double b = base[i];
    ret = pow(b, e);
    ret21 = s21_pow(b, e);
    if (s21_isnan(ret)) {
      ck_assert_ldouble_nan(ret);
      ck_assert_ldouble_nan(ret21);
    } else {
      ck_assert_ldouble_eq(ret, ret21);
    }
  }
}
END_TEST

START_TEST(e_is_nan) {
  double e;
  long double ret, ret21;
  double base[] = {
      0.0,           -0.0,       -1.0,      1.0,        -FLT_MIN,
      -FLT_MIN,      -2.0,       2,         0,          nan(""),
      -nan(""),      INFINITY,   -INFINITY, DBL_MAX,    -DBL_MAX,
      -100.0,        -101.0,     100.0,     101.0,      -100.5,
      -101.5,        100.5,      101.5,     -100.33333, -101.33333333,
      100.333333333, 101.3333333};

  e = nan("");
  for (size_t i = 0; i < sizeof(base) / sizeof(double); ++i) {
    double b = base[i];
    ret = pow(b, e);
    ret21 = s21_pow(b, e);
    if (s21_isnan(ret)) {
      ck_assert_ldouble_nan(ret);
      ck_assert_ldouble_nan(ret21);
    } else {
      ck_assert_ldouble_eq(ret, ret21);
    }
  }

  e = -nan("");
  for (size_t i = 0; i < sizeof(base) / sizeof(double); ++i) {
    double b = base[i];
    ret = pow(b, e);
    ret21 = s21_pow(b, e);
    if (s21_isnan(ret)) {
      ck_assert_ldouble_nan(ret);
      ck_assert_ldouble_nan(ret21);
    } else {
      ck_assert_ldouble_eq(ret, ret21);
    }
  }
}
END_TEST

START_TEST(inf) {
  double base;
  double e;
  long double ret;
  long double ret21;

  base = INFINITY;
  e = 0.0;
  ret = pow(base, e);
  ret21 = s21_pow(base, e);
  ck_assert_ldouble_eq(ret, ret21);
}
END_TEST

START_TEST(zero) {
  double x = 0.0;
  double e = 2;
  long double ret;
  long double ret21;

  ret = pow(x, e);
  ret21 = s21_pow(x, e);
  ck_assert_ldouble_eq(ret, ret21);
  e = -2.5;
  ret = pow(x, e);
  ret21 = s21_pow(x, e);
  ck_assert_ldouble_eq(ret, ret21);
}
END_TEST

START_TEST(zero_zero) {
  double x = 0.0;
  double e = 0;
  long double ret;
  long double ret21;

  ret = pow(x, e);
  ret21 = s21_pow(x, e);
  ck_assert_ldouble_eq(ret, ret21);
}
END_TEST

START_TEST(zero_to_nan) {
  double x = 0;
  double e = S21_NAN;
  long double ret;
  long double ret21;

  ret = pow(x, e);
  ret21 = s21_pow(x, e);
  ck_assert_ldouble_nan(ret);
  ck_assert_ldouble_nan(ret21);
}
END_TEST

START_TEST(one_to_nan) {
  double x = 1;
  double e = S21_NAN;
  long double ret;
  long double ret21;

  ret = pow(x, e);
  ret21 = s21_pow(x, e);
  ck_assert_ldouble_eq(ret, ret21);
}
END_TEST

START_TEST(nan_to_nan) {
  double x = S21_NAN;
  double e = S21_NAN;
  long double ret;
  long double ret21;

  ret = pow(x, e);
  ret21 = s21_pow(x, e);
  ck_assert_ldouble_nan(ret);
  ck_assert_ldouble_nan(ret21);
}
END_TEST

START_TEST(one_to_zero) {
  double x = 1;
  double e = 0;
  long double ret;
  long double ret21;

  ret = pow(x, e);
  ret21 = s21_pow(x, e);
  ck_assert_ldouble_eq(ret, ret21);
}
END_TEST

START_TEST(positive_zero) {
  double x = +0.0;
  double e = 2;
  long double ret;
  long double ret21;

  ret = pow(x, e);
  ret21 = s21_pow(x, e);
  ck_assert_ldouble_eq(ret, ret21);
}
END_TEST

START_TEST(negative_zero) {
  double x = -0.0;
  double e = 2;
  long double ret;
  long double ret21;

  ret = pow(x, e);
  ret21 = s21_pow(x, e);
  ck_assert_ldouble_eq(ret, ret21);
}
END_TEST

START_TEST(positive_x) {
  double x = +18742.3718;
  double e = 2;
  long double ret;
  long double ret21;

  ret = pow(x, e);
  ret21 = s21_pow(x, e);
  ck_assert_ldouble_eq_tol(ret, ret21, 1e-6);
}
END_TEST

START_TEST(positive_x_double_e) {
  double x = 187.3718;
  double e = 2.5;
  long double ret;
  long double ret21;

  ret = pow(x, e);
  ret21 = s21_pow(x, e);
  ck_assert_ldouble_eq_tol(ret, ret21, 1e-6);
}
END_TEST

START_TEST(negative_x) {
  double x = -128.18282;
  double e = 3.0;
  long double ret;
  long double ret21;

  ret = pow(x, e);
  ret21 = s21_pow(x, e);
  ck_assert_ldouble_eq_tol(ret, ret21, 1e-6);
}
END_TEST

START_TEST(negative_x_double_e) {
  double x = -12828.18282;
  double e = 2.5;
  long double ret;
  long double ret21;

  ret = pow(x, e);
  ret21 = s21_pow(x, e);
  ck_assert_ldouble_nan(ret);
  ck_assert_ldouble_nan(ret21);
}
END_TEST

START_TEST(positive_dbl_max) {
  double x = +DBL_MAX;
  double e = 2;
  long double ret;
  long double ret21;

  ret = pow(x, e);
  ret21 = s21_pow(x, e);
  ck_assert_ldouble_eq(ret, ret21);
}
END_TEST

START_TEST(positive_dbl_max_dbl_e) {
  double x = +DBL_MAX;
  double e = 2.5;
  long double ret;
  long double ret21;

  ret = pow(x, e);
  ret21 = s21_pow(x, e);
  ck_assert_ldouble_eq(ret, ret21);
}
END_TEST

START_TEST(negative_dbl_max) {
  double x = -DBL_MAX;
  double e = 2.5;
  long double ret;
  long double ret21;

  ret = pow(x, e);
  ret21 = s21_pow(x, e);
  ck_assert_ldouble_nan(ret);
  ck_assert_ldouble_nan(ret21);
}
END_TEST

START_TEST(positive_dbl_min) {
  double x = +DBL_MIN;
  double e = 2;
  long double ret;
  long double ret21;

  ret = pow(x, e);
  ret21 = s21_pow(x, e);
  ck_assert_ldouble_eq(ret, ret21);
}
END_TEST

START_TEST(negative_dbl_min) {
  double x = -DBL_MIN;
  double e = 2;
  long double ret;
  long double ret21;

  ret = pow(x, e);
  ret21 = s21_pow(x, e);
  ck_assert_ldouble_eq(ret, ret21);
}
END_TEST

START_TEST(positive_inf) {
  double x = +INFINITY;
  double e = 2;
  long double ret;
  long double ret21;

  ret = pow(x, e);
  ret21 = s21_pow(x, e);
  ck_assert_ldouble_eq(ret, ret21);
}
END_TEST

START_TEST(negative_inf) {
  double x = -INFINITY;
  double e = 2;
  long double ret;
  long double ret21;

  ret = pow(x, e);
  ret21 = s21_pow(x, e);
  ck_assert_ldouble_eq(ret, ret21);
}
END_TEST

START_TEST(one_to_inf_e) {
  double x = 1;
  double e = INFINITY;
  long double ret;
  long double ret21;

  ret = pow(x, e);
  ret21 = s21_pow(x, e);
  ck_assert_ldouble_eq(ret, ret21);
}
END_TEST

START_TEST(zero_to_inf_e) {
  double x = 0;
  double e = INFINITY;
  long double ret;
  long double ret21;

  ret = pow(x, e);
  ret21 = s21_pow(x, e);
  ck_assert_ldouble_eq(ret, ret21);
}
END_TEST

Suite *suite_s21_pow(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_pow");
  tc = tcase_create("s21_pow tcase");

  if (s != NULL && tc != NULL) {
    tcase_add_test(tc, e_zero);
    tcase_add_test(tc, e_one);
    tcase_add_test(tc, base_is_nan);
    tcase_add_test(tc, base_is_inf);
    tcase_add_test(tc, e_is_inf);
    tcase_add_test(tc, e_is_nan);
    tcase_add_test(tc, inf);
    tcase_add_test(tc, zero);
    tcase_add_test(tc, zero_zero);
    tcase_add_test(tc, zero_to_nan);
    tcase_add_test(tc, one_to_nan);
    tcase_add_test(tc, nan_to_nan);
    tcase_add_test(tc, one_to_zero);
    tcase_add_test(tc, positive_zero);
    tcase_add_test(tc, negative_zero);
    tcase_add_test(tc, positive_x);
    tcase_add_test(tc, positive_x_double_e);
    tcase_add_test(tc, negative_x);
    tcase_add_test(tc, negative_x_double_e);
    tcase_add_test(tc, positive_dbl_max);
    tcase_add_test(tc, positive_dbl_max_dbl_e);
    tcase_add_test(tc, negative_dbl_max);
    tcase_add_test(tc, positive_dbl_min);
    tcase_add_test(tc, negative_dbl_min);
    tcase_add_test(tc, positive_inf);
    tcase_add_test(tc, negative_inf);
    tcase_add_test(tc, one_to_inf_e);
    tcase_add_test(tc, zero_to_inf_e);
    suite_add_tcase(s, tc);
  }

  return (s);
}
