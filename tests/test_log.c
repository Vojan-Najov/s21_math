#include <check.h>
#include <math.h>

#include "s21_math.h"

START_TEST(inf_nan) {
  double num;
  double ret;
  double ret21;

  num = -nan("");
  ret = log(num);
  ret21 = s21_log(num);
  ck_assert_double_nan(ret);
  ck_assert_double_nan(ret21);
  num = nan("");
  ret = log(num);
  ret21 = s21_log(num);
  ck_assert_double_nan(ret);
  ck_assert_double_nan(ret21);
  num = -INFINITY;
  ret = log(num);
  ret21 = s21_log(num);
  ck_assert_double_nan(ret);
  ck_assert_double_nan(ret21);
  num = INFINITY;
  ret = log(num);
  ret21 = s21_log(num);
  ck_assert_double_eq(ret, ret21);
  ck_assert_double_infinite(ret);
  ck_assert_double_infinite(ret21);
}
END_TEST

START_TEST(negative_parametr) {
  double num;
  double ret;
  double ret21;

  num = -100.123;
  ret = log(num);
  ret21 = s21_log(num);
  ck_assert_double_nan(ret);
  ck_assert_double_nan(ret21);
  num = -1.5;
  ret = log(num);
  ret21 = s21_log(num);
  ck_assert_double_nan(ret);
  ck_assert_double_nan(ret21);
}
END_TEST

START_TEST(zero) {
  double num;
  double ret;
  double ret21;

  num = -0.0;
  ret = log(num);
  ret21 = s21_log(num);
  ck_assert_double_infinite(ret);
  ck_assert_double_infinite(ret21);
  ck_assert_double_lt(ret, 0.0);
  ck_assert_double_lt(ret21, 0.0);
  num = 0.0;
  ret = log(num);
  ret21 = s21_log(num);
  ck_assert_double_infinite(ret);
  ck_assert_double_infinite(ret21);
  ck_assert_double_lt(ret, 0.0);
  ck_assert_double_lt(ret21, 0.0);
}
END_TEST

static double nums1[] = {1.e-6, 1.e-5,  1.e-4,  1.e-3,   1.e-2,  1.e-1, 0.5,
                         0.245, 0.6547, 0.7641, 0.91912, 0.9999, 1.0,   1.5,
                         1.245, 1.6547, 1.7641, 1.91912, 1.9999, 2.0,   2.5,
                         2.245, 2.6547, 2.7641, 2.91912, 2.9999, S21_E};

static double len1 = sizeof(nums1) / sizeof(double);

START_TEST(small_parametr) {
  double num;
  double ret;
  double ret21;
  double eps = 1.0e-8;

  for (size_t i = 0; i < len1; ++i) {
    num = nums1[i];
    ret = log(num);
    ret21 = s21_log(num);
    ck_assert_double_eq_tol(ret, ret21, eps);
  }
}
END_TEST

static double nums2[] = {2 * S21_E,
                         10 * S21_E,
                         10.0,
                         12.567,
                         16.122,
                         21.383282,
                         51.383282,
                         80 * S21_E,
                         1024.121,
                         10000 * S21_E,
                         512.133818,
                         124251.282816,
                         1494919381.373718122,
                         1.0e15 * S21_E};

static double len2 = sizeof(nums2) / sizeof(double);

START_TEST(nums) {
  double num;
  double ret;
  double ret21;
  double eps = 1.0e-8;

  for (size_t i = 0; i < len2; ++i) {
    num = nums2[i];
    ret = log(num);
    ret21 = s21_log(num);
    ck_assert_double_eq_tol(ret, ret21, eps);
  }
}
END_TEST

Suite *suite_s21_log(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_log");
  tc = tcase_create("s21_log tcase");

  if (s != NULL && tc != NULL) {
    tcase_add_test(tc, inf_nan);
    tcase_add_test(tc, negative_parametr);
    tcase_add_test(tc, zero);
    tcase_add_test(tc, small_parametr);
    tcase_add_test(tc, nums);
    suite_add_tcase(s, tc);
  }

  return (s);
}
