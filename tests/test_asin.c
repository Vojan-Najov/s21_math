#include <check.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>

#include "s21_math.h"

static long double eps = 1.0e-06;

START_TEST(not_a_number) {
  double x = S21_NAN;
  long double ret21;
  ret21 = s21_asin(x);
  ck_assert_ldouble_nan(ret21);
}
END_TEST
START_TEST(neg_one) {
  double x = -1.0;
  long double ret;
  long double ret21;

  ret = asin(x);
  ret21 = s21_asin(x);
  ck_assert_ldouble_eq_tol(ret, ret21, 1e-06);
}
END_TEST

START_TEST(zero) {
  double x = 0;
  long double ret;
  long double ret21;

  ret = asin(x);
  ret21 = s21_asin(x);
  ck_assert_ldouble_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(neg_1) {
  double x = -1.0;
  long double ret;
  long double ret21;

  ret = asin(x);
  ret21 = s21_asin(x);
  ck_assert_ldouble_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(neg_2) {
  double x = -(S21_PI / 4);
  long double ret;
  long double ret21;

  ret = asin(x);
  ret21 = s21_asin(x);
  ck_assert_ldouble_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(neg_3) {
  double x = -(S21_PI / 6);
  long double ret;
  long double ret21;

  ret = asin(x);
  ret21 = s21_asin(x);
  ck_assert_ldouble_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(neg_4) {
  double x = -(S21_PI / 8);
  long double ret;
  long double ret21;

  ret = asin(x);
  ret21 = s21_asin(x);
  ck_assert_ldouble_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(neg_5) {
  double x = -0.001;
  long double ret;
  long double ret21;

  ret = asin(x);
  ret21 = s21_asin(x);
  ck_assert_ldouble_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(neg_6) {
  double x = -0.5;
  long double ret;
  long double ret21;

  ret = asin(x);
  ret21 = s21_asin(x);
  ck_assert_ldouble_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(neg_7) {
  double x = -0.1;
  long double ret;
  long double ret21;

  ret = asin(x);
  ret21 = s21_asin(x);
  ck_assert_ldouble_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(neg_8) {
  double x = -0.2345;
  long double ret;
  long double ret21;

  ret = asin(x);
  ret21 = s21_asin(x);
  ck_assert_ldouble_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(neg_9) {
  double x = -1234.1234;
  long double res;

  res = s21_asin(x);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(pos_1) {
  double x = 0.1;
  long double ret;
  long double ret21;

  ret = asin(x);
  ret21 = s21_asin(x);
  ck_assert_ldouble_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(pos_2) {
  double x = 0.001;
  long double ret;
  long double ret21;

  ret = asin(x);
  ret21 = s21_asin(x);
  ck_assert_ldouble_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(pos_3) {
  double x = 1.;
  long double ret;
  long double ret21;

  ret = asin(x);
  ret21 = s21_asin(x);
  ck_assert_ldouble_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(pos_4) {
  double x = (S21_PI / 4);
  long double ret;
  long double ret21;

  ret = asin(x);
  ret21 = s21_asin(x);
  ck_assert_ldouble_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(pos_5) {
  double x = (S21_PI / 6);
  long double ret;
  long double ret21;

  ret = asin(x);
  ret21 = s21_asin(x);
  ck_assert_ldouble_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(pos_6) {
  double x = 0.570796;
  long double ret;
  long double ret21;

  ret = asin(x);
  ret21 = s21_asin(x);
  ck_assert_ldouble_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(pos_7) {
  double x = 0.540302;
  long double ret;
  long double ret21;

  ret = asin(x);
  ret21 = s21_asin(x);
  ck_assert_ldouble_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(pos_8) {
  double x = 123455.13234;
  long double res;

  res = s21_asin(x);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(pos_9) {
  double x = 0.98765;
  long double ret;
  long double ret21;

  ret = asin(x);
  ret21 = s21_asin(x);
  ck_assert_ldouble_eq_tol(ret, ret21, eps);
}
END_TEST

Suite *suite_s21_asin(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_asin");
  tc = tcase_create("s21_asin tcase");

  if (s != NULL && tc != NULL) {
    tcase_add_test(tc, not_a_number);
    tcase_add_test(tc, neg_one);
    tcase_add_test(tc, zero);
    tcase_add_test(tc, neg_1);
    tcase_add_test(tc, neg_2);
    tcase_add_test(tc, neg_3);
    tcase_add_test(tc, neg_4);
    tcase_add_test(tc, neg_5);
    tcase_add_test(tc, neg_6);
    tcase_add_test(tc, neg_7);
    tcase_add_test(tc, neg_8);
    tcase_add_test(tc, neg_9);
    tcase_add_test(tc, pos_1);
    tcase_add_test(tc, pos_2);
    tcase_add_test(tc, pos_3);
    tcase_add_test(tc, pos_4);
    tcase_add_test(tc, pos_5);
    tcase_add_test(tc, pos_6);
    tcase_add_test(tc, pos_7);
    tcase_add_test(tc, pos_8);
    tcase_add_test(tc, pos_9);
    suite_add_tcase(s, tc);
  }

  return (s);
}
