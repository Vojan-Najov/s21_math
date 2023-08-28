#include <check.h>
#include <float.h>
#include <math.h>

#include "s21_math.h"

static double nums_negative[] = {-1.0,
                                 -1.1,
                                 -11.9888,
                                 -25.3570,
                                 -13.0675,
                                 -44.5435,
                                 -5.4645,
                                 -309457389.324234,
                                 -24658936.2347239847};

static double len_negative = sizeof(nums_negative) / sizeof(double);

START_TEST(negative_x) {
  double num_x;
  long double ret;
  long double ret21;

  for (size_t j = 0; j < len_negative; j++) {
    num_x = nums_negative[j];
    ret = trunc(num_x);
    ret21 = s21_trunc(num_x);
    ck_assert_ldouble_eq(ret, ret21);
  }
}
END_TEST

static double nums_positive[] = {
    1.0,     1.1,         5.17657,      7.578678,         7.43543457,
    2.78987, 10.54343256, 3467.2847293, 2347894.23423239,
};
static double len_positive = sizeof(nums_positive) / sizeof(double);

START_TEST(positive_x) {
  double num_x;
  long double ret;
  long double ret21;

  for (size_t j = 0; j < len_positive; j++) {
    num_x = nums_positive[j];
    ret = trunc(num_x);
    ret21 = s21_trunc(num_x);
    ck_assert_ldouble_eq(ret, ret21);
  }
}
END_TEST

START_TEST(ret_nan) {
  double x = S21_NAN;
  long double res;

  res = s21_trunc(x);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(ret_inf) {
  double x = S21_INFINITY;
  long double res;

  res = s21_trunc(x);
  ck_assert_ldouble_infinite(res);
}
END_TEST

START_TEST(zero) {
  double x = 0.0;
  long double ret;
  long double ret21;

  ret = trunc(x);
  ret21 = s21_trunc(x);
  ck_assert_ldouble_eq(ret, ret21);
}
END_TEST

START_TEST(positive_zero) {
  double x = +0.0;
  long double ret;
  long double ret21;

  ret = trunc(x);
  ret21 = s21_trunc(x);
  ck_assert_ldouble_eq(ret, ret21);
}
END_TEST

START_TEST(negative_zero) {
  double x = -0.0;
  long double ret;
  long double ret21;

  ret = trunc(x);
  ret21 = s21_trunc(x);
  ck_assert_ldouble_eq(ret, ret21);
}
END_TEST

START_TEST(positive_PI) {
  double x = +S21_PI;
  long double ret;
  long double ret21;

  ret = trunc(x);
  ret21 = s21_trunc(x);
  ck_assert_ldouble_eq(ret, ret21);
}
END_TEST

START_TEST(positive_PI_1_2) {
  double x = +S21_PI / 2;
  long double ret;
  long double ret21;

  ret = trunc(x);
  ret21 = s21_trunc(x);
  ck_assert_ldouble_eq(ret, ret21);
}
END_TEST

START_TEST(positive_2_PI) {
  double x = +S21_PI * 2;
  long double ret;
  long double ret21;

  ret = trunc(x);
  ret21 = s21_trunc(x);
  ck_assert_ldouble_eq(ret, ret21);
}
END_TEST

START_TEST(positive_2_PI_3) {
  double x = +S21_PI * 2 / 3;
  long double ret;
  long double ret21;

  ret = trunc(x);
  ret21 = s21_trunc(x);
  ck_assert_ldouble_eq(ret, ret21);
}
END_TEST

START_TEST(positive_PI_1_4) {
  double x = +S21_PI / 4;
  long double ret;
  long double ret21;

  ret = trunc(x);
  ret21 = s21_trunc(x);
  ck_assert_ldouble_eq(ret, ret21);
}
END_TEST

START_TEST(positive_PI_3_4) {
  double x = +S21_PI * 3 / 4;
  long double ret;
  long double ret21;

  ret = trunc(x);
  ret21 = s21_trunc(x);
  ck_assert_ldouble_eq(ret, ret21);
}
END_TEST

START_TEST(negative_PI) {
  double x = -S21_PI;
  long double ret;
  long double ret21;

  ret = trunc(x);
  ret21 = s21_trunc(x);
  ck_assert_ldouble_eq(ret, ret21);
}
END_TEST

START_TEST(negative_PI_1_2) {
  double x = -S21_PI / 2;
  long double ret;
  long double ret21;

  ret = trunc(x);
  ret21 = s21_trunc(x);
  ck_assert_ldouble_eq(ret, ret21);
}
END_TEST

START_TEST(negative_2_PI) {
  double x = -S21_PI * 2;
  long double ret;
  long double ret21;

  ret = trunc(x);
  ret21 = s21_trunc(x);
  ck_assert_ldouble_eq(ret, ret21);
}
END_TEST

START_TEST(negative_2_PI_3) {
  double x = -S21_PI * 2 / 3;
  long double ret;
  long double ret21;

  ret = trunc(x);
  ret21 = s21_trunc(x);
  ck_assert_ldouble_eq(ret, ret21);
}
END_TEST

START_TEST(negative_PI_1_4) {
  double x = -S21_PI * 4;
  long double ret;
  long double ret21;

  ret = trunc(x);
  ret21 = s21_trunc(x);
  ck_assert_ldouble_eq(ret, ret21);
}
END_TEST

START_TEST(negative_PI_3_4) {
  double x = -S21_PI * 3 / 4;
  long double ret;
  long double ret21;

  ret = trunc(x);
  ret21 = s21_trunc(x);
  ck_assert_ldouble_eq(ret, ret21);
}
END_TEST

START_TEST(positive_S21_MAX_DOUBLE) {
  double x = +S21_MAX_DOUBLE;
  long double ret;
  long double ret21;

  ret = trunc(x);
  ret21 = s21_trunc(x);
  ck_assert_ldouble_eq(ret, ret21);
}
END_TEST

START_TEST(negative_S21_MAX_DOUBLE) {
  double x = -S21_MAX_DOUBLE;
  long double ret;
  long double ret21;

  ret = trunc(x);
  ret21 = s21_trunc(x);
  ck_assert_ldouble_eq(ret, ret21);
}
END_TEST

START_TEST(positive_dbl_min) {
  double x = +DBL_MIN;
  long double ret;
  long double ret21;

  ret = trunc(x);
  ret21 = s21_trunc(x);
  ck_assert_ldouble_eq(ret, ret21);
}
END_TEST

START_TEST(negative_dbl_min) {
  double x = -DBL_MIN;
  long double ret;
  long double ret21;

  ret = trunc(x);
  ret21 = s21_trunc(x);
  ck_assert_ldouble_eq(ret, ret21);
}
END_TEST

START_TEST(positive_inf) {
  double x = +S21_INFINITY;
  long double ret;
  long double ret21;

  ret = trunc(x);
  ret21 = s21_trunc(x);
  ck_assert_ldouble_eq(ret, ret21);
}
END_TEST

START_TEST(negative_inf) {
  double x = -S21_INFINITY;
  long double ret;
  long double ret21;

  ret = trunc(x);
  ret21 = s21_trunc(x);
  ck_assert_ldouble_eq(ret, ret21);
}
END_TEST

Suite *suite_s21_trunc(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_trunc");
  tc = tcase_create("s21_trunc tcase");

  if (s != NULL && tc != NULL) {
    tcase_add_test(tc, ret_nan);
    tcase_add_test(tc, ret_inf);
    tcase_add_test(tc, zero);
    tcase_add_test(tc, positive_zero);
    tcase_add_test(tc, negative_zero);
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
    tcase_add_test(tc, negative_S21_MAX_DOUBLE);
    tcase_add_test(tc, positive_dbl_min);
    tcase_add_test(tc, negative_dbl_min);
    tcase_add_test(tc, positive_inf);
    tcase_add_test(tc, negative_inf);
    suite_add_tcase(s, tc);
  }

  return (s);
}
