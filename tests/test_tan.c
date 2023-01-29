#include <check.h>
#include <float.h>
#include <math.h>

#include "s21_math.h"

static double eps = 1.0e-06;

START_TEST(zero) {
  double x = 0.0;
  double ret;
  double ret21;

  ret = tan(x);
  ret21 = s21_tan(x);
  ck_assert_double_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(ret_nan1) {
  double x = S21_NAN;
  double res;

  res = s21_tan(x);
  ck_assert_double_nan(res);
}
END_TEST

START_TEST(ret_nan2) {
  double x = S21_INFINITY;
  double res;

  res = s21_tan(x);
  ck_assert_double_nan(res);
}
END_TEST

START_TEST(ret_nan3) {
  double x = -S21_INFINITY;
  double res;

  res = s21_tan(x);
  ck_assert_double_nan(res);
}
END_TEST

static double nums[] = {-1.0,
                        1.1,
                        12.98,
                        -23.3430,
                        -15.0675,
                        -43.5335,
                        203457389.324234,
                        -24658936.2347239847,
                        S21_PI,
                        -S21_PI,
                        S21_PI / 4,
                        -S21_PI / 4,
                        S21_PI / 6,
                        -S21_PI / 6,
                        3 * S21_PI / 4,
                        -3 * S21_PI / 4,
                        S21_PI / 3,
                        -S21_PI / 3};

static int len_nums = sizeof(nums) / sizeof(double);

START_TEST(nums_set) {
  double x;
  double ret;
  double ret21;
  for (int j = 0; j < len_nums; j++) {
    x = nums[j];
    ret = tan(x);
    ret21 = s21_tan(x);
    ck_assert_double_eq_tol(ret, ret21, eps);
  }
}
END_TEST

START_TEST(positive_dbl_min) {
  double x = +DBL_MIN;
  double ret;
  double ret21;

  ret = tan(x);
  ret21 = s21_tan(x);
  ck_assert_double_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(negative_dbl_min) {
  double x = -DBL_MIN;
  double ret;
  double ret21;

  ret = tan(x);
  ret21 = s21_tan(x);
  ck_assert_double_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(pi_2) {
  double x;
  double ret;
  double ret21;

  x = S21_PI / 2.0;
  ret = tan(x);
  ret21 = s21_tan(x);
  ck_assert_double_eq_tol(ret, ret21, eps);

  x = -S21_PI / 2.0;
  ret = tan(x);
  ret21 = s21_tan(x);
  ck_assert_double_eq_tol(ret, ret21, eps);
}

Suite *suite_s21_tan(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_tan");
  tc = tcase_create("s21_tan tcase");

  if (s != NULL && tc != NULL) {
    tcase_add_test(tc, zero);
    tcase_add_test(tc, ret_nan1);
    tcase_add_test(tc, ret_nan2);
    tcase_add_test(tc, ret_nan3);
    tcase_add_test(tc, nums_set);
    tcase_add_test(tc, positive_dbl_min);
    tcase_add_test(tc, negative_dbl_min);
    tcase_add_test(tc, pi_2);
    suite_add_tcase(s, tc);
  }

  return (s);
}
