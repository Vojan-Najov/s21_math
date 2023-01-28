#include "s21_math.h"
#include <check.h>
#include <math.h>

START_TEST(num) {
  double x = 21271.218121;
  ck_assert(s21_isnan(x) == 0);
  x = -21271.218121;
  ck_assert(s21_isnan(x) == 0);
  x = 2.218121e-16;
  ck_assert(s21_isnan(x) == 0);
  x = 2.1271218121e10;
  ck_assert(s21_isnan(x) == 0);
}
END_TEST

START_TEST(isnan) {
  double x = nan("");
  ck_assert(s21_isnan(x));
  x = -nan("");
  ck_assert(s21_isnan(x));
}
END_TEST

START_TEST(zero) {
  double x = 0.0;
  ck_assert(s21_isnan(x) == 0);
  x = -0.0;
  ck_assert(s21_isnan(x) == 0);
}
END_TEST

START_TEST(inf) {
  double x = INFINITY;
  ck_assert(s21_isnan(x) == 0);
  x = -INFINITY;
  ck_assert(s21_isnan(x) == 0);
}
END_TEST

START_TEST(not_a_number) {
  double x;
  x = S21_NAN;
  ck_assert_double_nan(x);
  x = -S21_NAN;
  ck_assert_double_nan(x);
}
END_TEST

Suite *suite_s21_isnan(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_isnan");
  tc = tcase_create("s21_isnan tcase");

  if (s != NULL && tc != NULL) {
    tcase_add_test(tc, num);
    tcase_add_test(tc, isnan);
    tcase_add_test(tc, zero);
    tcase_add_test(tc, inf);
    tcase_add_test(tc, not_a_number);
    suite_add_tcase(s, tc);
  }

  return (s);
}
