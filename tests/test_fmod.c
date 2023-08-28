#include <check.h>
#include <float.h>
#include <math.h>

#include "s21_math.h"

static long double eps = 1.0e-6;

static double nums_negative[] = {-11.9888,
                                 -25.3570,
                                 -13.0675,
                                 -44.5435,
                                 -5.4645,
                                 -309457389.324234,
                                 -24658936.2347239847};

static double len_negative = sizeof(nums_negative) / sizeof(double);

static double nums_positive[] = {
    5.17657,     7.578678,     7.43543457,       2.78987,
    10.54343256, 3467.2847293, 2347894.23423239,
};
static double len_positive = sizeof(nums_positive) / sizeof(double);

START_TEST(ret_nan_x) {
  double x = S21_NAN;
  double y = 1.0;
  long double res;

  res = s21_fmod(x, y);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(ret_nan_y) {
  double y = S21_NAN;
  double x = 1.0;
  long double res;

  res = s21_fmod(x, y);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(ret_nan_x2) {
  double x = S21_INFINITY;
  double y = 1.0;
  long double res;

  res = s21_fmod(x, y);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(zero) {
  double x = 0.0;
  double y = 1.0;
  long double ret;
  long double ret21;

  ret = fmod(x, y);
  ret21 = s21_fmod(x, y);
  ck_assert_ldouble_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(zero_y) {
  double x = 1.0;
  double y = 0.0;
  long double ret21;

  ret21 = s21_fmod(x, y);
  ck_assert_ldouble_nan(ret21);
}
END_TEST

START_TEST(positive_zero) {
  double x = +0.0;
  double y = +1.0;
  long double ret;
  long double ret21;

  ret = fmod(x, y);
  ret21 = s21_fmod(x, y);
  ck_assert_ldouble_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(negative_zero) {
  double x = -0.0;
  double y = -1.0;
  long double ret;
  long double ret21;

  ret = fmod(x, y);
  ret21 = s21_fmod(x, y);
  ck_assert_ldouble_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(positive_zero_y) {
  double x = +1.0;
  double y = +0.0;
  long double ret21;

  ret21 = s21_fmod(x, y);
  ck_assert_ldouble_nan(ret21);
}
END_TEST

START_TEST(negative_zero_y) {
  double x = -1.0;
  double y = -0.0;
  long double ret21;

  ret21 = s21_fmod(x, y);
  ck_assert_ldouble_nan(ret21);
}
END_TEST

START_TEST(positive_x) {
  double x = +1874.3718;
  double y = 1.0;
  long double ret;
  long double ret21;

  ret = fmod(x, y);
  ret21 = s21_fmod(x, y);
  ck_assert_ldouble_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(positive_PI) {
  double x = +S21_PI;
  double y = 1.0;
  long double ret;
  long double ret21;

  ret = fmod(x, y);
  ret21 = s21_fmod(x, y);
  ck_assert_ldouble_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(positive_PI_1_2) {
  double x = +S21_PI / 2;
  double y = 1.0;
  long double ret;
  long double ret21;

  ret = fmod(x, y);
  ret21 = s21_fmod(x, y);
  ck_assert_ldouble_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(positive_2_PI) {
  double x = +S21_PI * 2;
  double y = 1.0;
  long double ret;
  long double ret21;

  ret = fmod(x, y);
  ret21 = s21_fmod(x, y);
  ck_assert_ldouble_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(positive_2_PI_3) {
  double x = +S21_PI * 2 / 3;
  double y = 1.0;
  long double ret;
  long double ret21;

  ret = fmod(x, y);
  ret21 = s21_fmod(x, y);
  ck_assert_ldouble_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(positive_PI_1_4) {
  double x = +S21_PI / 4;
  double y = 1.0;
  long double ret;
  long double ret21;

  ret = fmod(x, y);
  ret21 = s21_fmod(x, y);
  ck_assert_ldouble_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(positive_PI_3_4) {
  double x = +S21_PI * 3 / 4;
  double y = 1.0;
  long double ret;
  long double ret21;

  ret = fmod(x, y);
  ret21 = s21_fmod(x, y);
  ck_assert_ldouble_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(negative_x) {
  double num_x;
  double num_y;
  long double ret;
  long double ret21;

  for (size_t i = 0; i < len_negative; i++) {
    for (size_t j = 0; j < len_positive; j++) {
      num_x = nums_negative[i];
      num_y = nums_positive[j];
      ret = fmod(num_x, num_y);
      ret21 = s21_fmod(num_x, num_y);
      ck_assert_ldouble_eq_tol(ret, ret21, eps);
    }
  }
}
END_TEST

START_TEST(negative_PI) {
  double x = -S21_PI;
  double y = 1.0;
  long double ret;
  long double ret21;

  ret = fmod(x, y);
  ret21 = s21_fmod(x, y);
  ck_assert_ldouble_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(negative_PI_1_2) {
  double x = -S21_PI / 2;
  double y = 1.0;
  long double ret;
  long double ret21;

  ret = fmod(x, y);
  ret21 = s21_fmod(x, y);
  ck_assert_ldouble_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(negative_2_PI) {
  double x = -S21_PI * 2;
  double y = 1.0;
  long double ret;
  long double ret21;

  ret = fmod(x, y);
  ret21 = s21_fmod(x, y);
  ck_assert_ldouble_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(negative_2_PI_3) {
  double x = -S21_PI * 2 / 3;
  double y = 1.0;
  long double ret;
  long double ret21;

  ret = fmod(x, y);
  ret21 = s21_fmod(x, y);
  ck_assert_ldouble_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(negative_PI_1_4) {
  double x = -S21_PI * 4;
  double y = 1.0;
  long double ret;
  long double ret21;

  ret = fmod(x, y);
  ret21 = s21_fmod(x, y);
  ck_assert_ldouble_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(negative_PI_3_4) {
  double x = -S21_PI * 3 / 4;
  double y = 1.0;
  long double ret;
  long double ret21;

  ret = fmod(x, y);
  ret21 = s21_fmod(x, y);
  ck_assert_ldouble_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(positive_S21_MAX_DOUBLE) {
  double x = +S21_MAX_DOUBLE;
  double y = 1.0;
  long double ret;
  long double ret21;

  ret = fmod(x, y);
  ret21 = s21_fmod(x, y);
  ck_assert_ldouble_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(positive_dbl_min) {
  double x = +DBL_MIN;
  double y = 1.0;
  long double ret;
  long double ret21;

  ret = fmod(x, y);
  ret21 = s21_fmod(x, y);
  ck_assert_ldouble_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(negative_dbl_min) {
  double x = -DBL_MIN;
  double y = 1.0;
  long double ret;
  long double ret21;

  ret = fmod(x, y);
  ret21 = s21_fmod(x, y);
  ck_assert_ldouble_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(infinity) {
  double x;
  double y;
  long double ret;
  long double ret21;

  x = INFINITY;
  y = -1;
  ret = fmod(x, y);
  ret21 = s21_fmod(x, y);
  ck_assert_ldouble_nan(ret);
  ck_assert_ldouble_nan(ret21);

  x = -1;
  y = -INFINITY;
  ret = fmod(x, y);
  ret21 = s21_fmod(x, y);
  ck_assert_ldouble_eq(ret, ret21);

  x = 0;
  y = INFINITY;
  ret = fmod(x, y);
  ret21 = s21_fmod(x, y);
  ck_assert_ldouble_eq(ret, ret21);

  x = nan("");
  y = INFINITY;
  ret = fmod(x, y);
  ret21 = s21_fmod(x, y);
  ck_assert_ldouble_nan(ret);
  ck_assert_ldouble_nan(ret21);

  x = INFINITY;
  y = nan("");
  ret = fmod(x, y);
  ret21 = s21_fmod(x, y);
  ck_assert_ldouble_nan(ret);
  ck_assert_ldouble_nan(ret21);

  x = nan("");
  y = -INFINITY;
  ret = fmod(x, y);
  ret21 = s21_fmod(x, y);
  ck_assert_ldouble_nan(ret);
  ck_assert_ldouble_nan(ret21);

  x = -INFINITY;
  y = nan("");
  ret = fmod(x, y);
  ret21 = s21_fmod(x, y);
  ck_assert_ldouble_nan(ret);
  ck_assert_ldouble_nan(ret21);

  x = 2.4;
  y = INFINITY;
  ret = fmod(x, y);
  ret21 = s21_fmod(x, y);
  ck_assert_ldouble_eq_tol(ret, ret21, eps);
}
END_TEST

Suite *suite_s21_fmod(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_fmod");
  tc = tcase_create("s21_fmod tcase");

  if (s != NULL && tc != NULL) {
    tcase_add_test(tc, zero);
    tcase_add_test(tc, ret_nan_x);
    tcase_add_test(tc, ret_nan_x2);
    tcase_add_test(tc, ret_nan_y);
    tcase_add_test(tc, positive_zero);
    tcase_add_test(tc, negative_zero);
    tcase_add_test(tc, zero_y);
    tcase_add_test(tc, positive_zero_y);
    tcase_add_test(tc, negative_zero_y);
    tcase_add_test(tc, positive_x);
    tcase_add_test(tc, positive_PI);
    tcase_add_test(tc, positive_PI_1_2);
    tcase_add_test(tc, positive_2_PI);
    tcase_add_test(tc, positive_2_PI_3);
    tcase_add_test(tc, positive_PI_1_4);
    tcase_add_test(tc, positive_PI_3_4);
    tcase_add_test(tc, negative_x);
    tcase_add_test(tc, negative_PI);
    tcase_add_test(tc, negative_PI_1_2);
    tcase_add_test(tc, negative_2_PI);
    tcase_add_test(tc, negative_2_PI_3);
    tcase_add_test(tc, negative_PI_1_4);
    tcase_add_test(tc, negative_PI_3_4);
    tcase_add_test(tc, positive_S21_MAX_DOUBLE);
    tcase_add_test(tc, positive_dbl_min);
    tcase_add_test(tc, negative_dbl_min);
    tcase_add_test(tc, infinity);
    suite_add_tcase(s, tc);
  }
  return (s);
}
