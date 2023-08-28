#include <check.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>

#include "s21_math.h"
START_TEST(not_a_number) {
  double x = S21_NAN;
  long double ret21;
  ret21 = s21_atan(x);
  ck_assert_ldouble_nan(ret21);
}
END_TEST
START_TEST(neg_inf) {
  double x = -S21_INFINITY;
  long double ret;
  long double ret21;

  ret = atan(x);
  ret21 = s21_atan(x);
  ck_assert_ldouble_eq_tol(ret, ret21, 1e-06);
}
END_TEST

START_TEST(pos_inf) {
  double x = S21_INFINITY;
  long double ret;
  long double ret21;

  ret = atan(x);
  ret21 = s21_atan(x);
  ck_assert_ldouble_eq_tol(ret, ret21, 1e-06);
}
END_TEST

START_TEST(zero) {
  double x = 0;
  long double ret;
  long double ret21;

  ret = atan(x);
  ret21 = s21_atan(x);
  ck_assert_ldouble_eq_tol(ret, ret21, 1e-06);
}
END_TEST

START_TEST(neg_1) {
  double x = -1.0;
  long double ret;
  long double ret21;

  ret = atan(x);
  ret21 = s21_atan(x);
  ck_assert_ldouble_eq_tol(ret, ret21, 1e-06);
}
END_TEST

START_TEST(neg_2) {
  double x = -1234;
  long double ret;
  long double ret21;

  ret = atan(x);
  ret21 = s21_atan(x);
  ck_assert_ldouble_eq_tol(ret, ret21, 1e-06);
}
END_TEST

START_TEST(neg_3) {
  double x = -12.123456;
  long double ret;
  long double ret21;

  ret = atan(x);
  ret21 = s21_atan(x);
  ck_assert_ldouble_eq_tol(ret, ret21, 1e-06);
}
END_TEST

START_TEST(neg_4) {
  double x = -12123456;
  long double ret;
  long double ret21;

  ret = atan(x);
  ret21 = s21_atan(x);
  ck_assert_ldouble_eq_tol(ret, ret21, 1e-06);
}
END_TEST

START_TEST(neg_5) {
  double x = -S21_PI;
  long double ret;
  long double ret21;

  ret = atan(x);
  ret21 = s21_atan(x);
  ck_assert_ldouble_eq_tol(ret, ret21, 1e-06);
}
END_TEST

START_TEST(neg_6) {
  double x = -(S21_PI / 2);
  long double ret;
  long double ret21;

  ret = atan(x);
  ret21 = s21_atan(x);
  ck_assert_ldouble_eq_tol(ret, ret21, 1e-06);
}
END_TEST

START_TEST(neg_7) {
  double x = -(S21_PI / 6);
  long double ret;
  long double ret21;

  ret = atan(x);
  ret21 = s21_atan(x);
  ck_assert_ldouble_eq_tol(ret, ret21, 1e-06);
}
END_TEST

START_TEST(neg_8) {
  double x = -2;
  long double ret;
  long double ret21;

  ret = atan(x);
  ret21 = s21_atan(x);
  ck_assert_ldouble_eq_tol(ret, ret21, 1e-06);
}
END_TEST

START_TEST(neg_9) {
  double x = -123456789.123456789;
  long double ret;
  long double ret21;

  ret = atan(x);
  ret21 = s21_atan(x);
  ck_assert_ldouble_eq_tol(ret, ret21, 1e-06);
}
END_TEST

START_TEST(neg_10) {
  double x = -0.0123;
  long double ret;
  long double ret21;

  ret = atan(x);
  ret21 = s21_atan(x);
  ck_assert_ldouble_eq_tol(ret, ret21, 1e-06);
}
END_TEST

START_TEST(pos_1) {
  double x = 1.0;
  long double ret;
  long double ret21;

  ret = atan(x);
  ret21 = s21_atan(x);
  ck_assert_ldouble_eq_tol(ret, ret21, 1e-06);
}
END_TEST

START_TEST(pos_2) {
  double x = 123345;
  long double ret;
  long double ret21;

  ret = atan(x);
  ret21 = s21_atan(x);
  ck_assert_ldouble_eq_tol(ret, ret21, 1e-06);
}
END_TEST

START_TEST(pos_3) {
  double x = 12.3456;
  long double ret;
  long double ret21;

  ret = atan(x);
  ret21 = s21_atan(x);
  ck_assert_ldouble_eq_tol(ret, ret21, 1e-06);
}
END_TEST

START_TEST(pos_4) {
  double x = 0.001234;
  long double ret;
  long double ret21;

  ret = atan(x);
  ret21 = s21_atan(x);
  ck_assert_ldouble_eq_tol(ret, ret21, 1e-06);
}
END_TEST

START_TEST(pos_5) {
  double x = S21_PI;
  long double ret;
  long double ret21;

  ret = atan(x);
  ret21 = s21_atan(x);
  ck_assert_ldouble_eq_tol(ret, ret21, 1e-06);
}
END_TEST

START_TEST(pos_6) {
  double x = (S21_PI / 2);
  long double ret;
  long double ret21;

  ret = atan(x);
  ret21 = s21_atan(x);
  ck_assert_ldouble_eq_tol(ret, ret21, 1e-06);
}
END_TEST

START_TEST(pos_7) {
  double x = (S21_PI / 6);
  long double ret;
  long double ret21;

  ret = atan(x);
  ret21 = s21_atan(x);
  ck_assert_ldouble_eq_tol(ret, ret21, 1e-06);
}
END_TEST

START_TEST(pos_8) {
  double x = 123456789.123456789;
  long double ret;
  long double ret21;

  ret = atan(x);
  ret21 = s21_atan(x);
  ck_assert_ldouble_eq_tol(ret, ret21, 1e-06);
}
END_TEST

START_TEST(pos_9) {
  double x = 2;
  long double ret;
  long double ret21;

  ret = atan(x);
  ret21 = s21_atan(x);
  ck_assert_ldouble_eq_tol(ret, ret21, 1e-06);
}
END_TEST

START_TEST(pos_10) {
  double x = S21_EPS;
  long double ret;
  long double ret21;

  ret = atan(x);
  ret21 = s21_atan(x);
  ck_assert_ldouble_eq_tol(ret, ret21, 1e-06);
}
END_TEST

Suite *suite_s21_atan(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_atan");
  tc = tcase_create("s21_atan tcase");

  if (s != NULL && tc != NULL) {
    tcase_add_test(tc, not_a_number);
    tcase_add_test(tc, neg_inf);
    tcase_add_test(tc, pos_inf);
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
    tcase_add_test(tc, neg_10);
    tcase_add_test(tc, pos_1);
    tcase_add_test(tc, pos_2);
    tcase_add_test(tc, pos_3);
    tcase_add_test(tc, pos_4);
    tcase_add_test(tc, pos_5);
    tcase_add_test(tc, pos_6);
    tcase_add_test(tc, pos_7);
    tcase_add_test(tc, pos_8);
    tcase_add_test(tc, pos_9);
    tcase_add_test(tc, pos_10);
    suite_add_tcase(s, tc);
  }

  return (s);
}
