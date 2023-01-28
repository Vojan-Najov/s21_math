#include "s21_math.h"
#include <check.h>
#include <float.h>
#include <math.h>

START_TEST(num) {
  double x = 21271.218121;
  ck_assert(s21_isinf(x) == 0);
  x = -21271.218121;
  ck_assert(s21_isinf(x) == 0);
  x = 2.218121e-16;
  ck_assert(s21_isinf(x) == 0);
  x = 2.1271218121e10;
  ck_assert(s21_isinf(x) == 0);
  x = DBL_MIN;
  ck_assert(s21_isinf(x) == 0);
  x = DBL_MAX;
  ck_assert(s21_isinf(x) == 0);
}
END_TEST

START_TEST(isnan) {
  double x = nan("");
  ck_assert(s21_isinf(x) == 0);
  x = -nan("");
  ck_assert(s21_isinf(x) == 0);
}
END_TEST

START_TEST(zero) {
  double x = 0.0;
  ck_assert(s21_isinf(x) == 0);
  x = -0.0;
  ck_assert(s21_isinf(x) == 0);
}
END_TEST

START_TEST(inf) {
  double x = INFINITY;
  ck_assert(s21_isinf(x));
  x = -INFINITY;
  ck_assert(s21_isinf(x));
}
END_TEST

Suite *suite_s21_isinf(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_isinf");
  tc = tcase_create("s21_isinf tcase");

  if (s != NULL && tc != NULL) {
    tcase_add_test(tc, num);
    tcase_add_test(tc, isnan);
    tcase_add_test(tc, zero);
    tcase_add_test(tc, inf);
    suite_add_tcase(s, tc);
  }

  return (s);
}
