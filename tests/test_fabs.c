#include <check.h>
#include <float.h>
#include <math.h>

#include "s21_math.h"

START_TEST(zero) {
  double x;
  double ret;
  double ret21;

  x = 0.0;
  ret = fabs(x);
  ret21 = s21_fabs(x);
  ck_assert_double_eq(ret, ret21);
  x = -0.0;
}
END_TEST

static double nums[] = {-1229121.2911212, -282.21812 - 1.0e12,
                        -1.393,           -0.99999,
                        0.992992,         1.0e-6,
                        1.0e-1,           1.0e4,
                        1.0e-10,          1.0e5,
                        1.0e10,           -1.0e-6,
                        -1.0e-1,          -1.0e4,
                        -1.0e-10,         -1.0e5,
                        -1.0e10};

static size_t nums_len = sizeof(nums) / sizeof(double);

START_TEST(dbl_nums) {
  double x;
  double ret;
  double ret21;

  for (size_t i = 0; i < nums_len; ++i) {
    x = nums[i];
    ret = fabs(x);
    ret21 = s21_fabs(x);
    ck_assert_double_eq(ret, ret21);
  }
}
END_TEST

START_TEST(dbl_limits) {
  double x;
  double ret;
  double ret21;

  x = FLT_MIN;
  ret = fabs(x);
  ret21 = s21_fabs(x);
  ck_assert_double_eq(ret, ret21);
  x = -FLT_MIN;
  ret = fabs(x);
  ret21 = s21_fabs(x);
  ck_assert_double_eq(ret, ret21);
  x = FLT_MAX;
  ret = fabs(x);
  ret21 = s21_fabs(x);
  ck_assert_double_eq(ret, ret21);
  x = -FLT_MAX;
  ret = fabs(x);
  ret21 = s21_fabs(x);
  ck_assert_double_eq(ret, ret21);
  x = DBL_MIN;
  ret = fabs(x);
  ret21 = s21_fabs(x);
  ck_assert_double_eq(ret, ret21);
  x = -DBL_MIN;
  ret = fabs(x);
  ret21 = s21_fabs(x);
  ck_assert_double_eq(ret, ret21);
  x = DBL_MAX;
  ret = fabs(x);
  ret21 = s21_fabs(x);
  ck_assert_double_eq(ret, ret21);
  x = -DBL_MAX;
  ret = fabs(x);
  ret21 = s21_fabs(x);
  ck_assert_double_eq(ret, ret21);
}
END_TEST

START_TEST(inf_nan) {
  double x;
  double ret;
  double ret21;

  x = INFINITY;
  ret = fabs(x);
  ret21 = s21_fabs(x);
  ck_assert_double_infinite(ret);
  ck_assert_double_infinite(ret21);
  ck_assert(ret > 0 && ret21 > 0);
  x = -INFINITY;
  ret = fabs(x);
  ret21 = s21_fabs(x);
  ck_assert_double_infinite(ret);
  ck_assert_double_infinite(ret21);
  ck_assert(ret > 0 && ret21 > 0);
  x = nan("");
  ret = fabs(x);
  ret21 = s21_fabs(x);
  ck_assert_double_nan(ret);
  ck_assert_double_nan(ret21);
  x = -nan("");
  ret = fabs(x);
  ret21 = s21_fabs(x);
  ck_assert_double_nan(ret);
  ck_assert_double_nan(ret21);
}
END_TEST

Suite *suite_s21_fabs(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_fabs");
  tc = tcase_create("s21_fabs tcase");

  if (s != NULL && tc != NULL) {
    tcase_add_test(tc, zero);
    tcase_add_test(tc, dbl_limits);
    tcase_add_test(tc, inf_nan);
    tcase_add_test(tc, dbl_nums);
    suite_add_tcase(s, tc);
  }

  return (s);
}
