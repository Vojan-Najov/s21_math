#include <check.h>
#include <float.h>
#include <math.h>

#include "s21_math.h"

START_TEST(zero) {
  double num;
  double ret;
  double ret21;

  num = 0.0;
  ret = ceil(num);
  ret21 = s21_ceil(num);
  ck_assert_double_eq(ret, ret21);
  num = -0.0;
  ret = ceil(num);
  ret21 = s21_ceil(num);
  ck_assert_double_eq(ret, ret21);
}
END_TEST

START_TEST(positive_049) {
  double num = 0.49;
  double ret;
  double ret21;

  ret = ceil(num);
  ret21 = s21_ceil(num);
  ck_assert_double_eq(ret, ret21);
}
END_TEST

START_TEST(negative_049) {
  double num = -0.49;
  double ret;
  double ret21;

  ret = ceil(num);
  ret21 = s21_ceil(num);
  ck_assert_double_eq(ret, ret21);
}
END_TEST

START_TEST(positive_05) {
  double num = 0.5;
  double ret;
  double ret21;

  ret = ceil(num);
  ret21 = s21_ceil(num);
  ck_assert_double_eq(ret, ret21);
}
END_TEST

START_TEST(negative_05) {
  double num = -0.5;
  double ret;
  double ret21;

  ret = ceil(num);
  ret21 = s21_ceil(num);
  ck_assert_double_eq(ret, ret21);
}
END_TEST

START_TEST(dbl_limits) {
  double num;
  double ret;
  double ret21;

  num = -FLT_MIN;
  ret = ceil(num);
  ret21 = s21_ceil(num);
  ck_assert_double_eq(ret, ret21);
  num = FLT_MIN;
  ret = ceil(num);
  ret21 = s21_ceil(num);
  ck_assert_double_eq(ret, ret21);
  num = -FLT_MAX;
  ret = ceil(num);
  ret21 = s21_ceil(num);
  ck_assert_double_eq(ret, ret21);
  num = FLT_MAX;
  ret = ceil(num);
  ret21 = s21_ceil(num);
  ck_assert_double_eq(ret, ret21);
  num = -DBL_MIN;
  ret = ceil(num);
  ret21 = s21_ceil(num);
  ck_assert_double_eq(ret, ret21);
  num = DBL_MIN;
  ret = ceil(num);
  ret21 = s21_ceil(num);
  ck_assert_double_eq(ret, ret21);
  num = -DBL_MAX;
  ret = ceil(num);
  ret21 = s21_ceil(num);
  ck_assert_double_eq(ret, ret21);
  num = -DBL_MAX;
  ret = ceil(num);
  ret21 = s21_ceil(num);
  ck_assert_double_eq(ret, ret21);
}
END_TEST

START_TEST(inf_nan) {
  double num;
  double ret;
  double ret21;

  num = INFINITY;
  ret = ceil(num);
  ret21 = s21_ceil(num);
  ck_assert_double_eq(ret, ret21);
  num = -INFINITY;
  ret = ceil(num);
  ret21 = s21_ceil(num);
  ck_assert_double_eq(ret, ret21);
  num = -nan("");
  ret = ceil(num);
  ret21 = s21_ceil(num);
  ck_assert_double_nan(ret);
  ck_assert_double_nan(ret21);
  num = nan("");
  ret = ceil(num);
  ret21 = s21_ceil(num);
  ck_assert_double_nan(ret);
  ck_assert_double_nan(ret21);
}
END_TEST

static double nums[] = {-1.0,
                        +1.0,
                        -FLT_MAX,
                        FLT_MAX,
                        -FLT_MIN,
                        FLT_MIN,
                        -1.2,
                        1.2,
                        -99.99999999,
                        99.99999999,
                        -2,
                        2,
                        -100.0,
                        101.0,
                        -0.005,
                        0.005,
                        -3.00000001,
                        3.00000001,
                        107.8,
                        4.4,
                        -19764.034 - 16.73,
                        -18.24,
                        15.12,
                        -10.000000000008,
                        10.0000000008,
                        -217211262167.2712721721,
                        217211262167.2712721721,
                        -636236326262636236.12721721,
                        636236326262636236.12721721};

static size_t numlen = sizeof(nums) / sizeof(double);

START_TEST(test_nums) {
  double ret;
  double ret21;

  for (size_t i = 0; i < numlen; ++i) {
    ret = ceil(nums[i]);
    ret21 = s21_ceil(nums[i]);
    ck_assert_double_eq(ret, ret21);
  }
}
END_TEST

Suite *suite_s21_ceil(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_ceil");
  tc = tcase_create("s21_ceil create");

  if (s != NULL && tc != NULL) {
    tcase_add_test(tc, zero);
    tcase_add_test(tc, positive_049);
    tcase_add_test(tc, negative_049);
    tcase_add_test(tc, positive_05);
    tcase_add_test(tc, negative_05);
    tcase_add_test(tc, dbl_limits);
    tcase_add_test(tc, inf_nan);
    tcase_add_test(tc, test_nums);
    suite_add_tcase(s, tc);
  }

  return (s);
}
