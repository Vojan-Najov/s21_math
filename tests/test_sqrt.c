#include <check.h>
#include <float.h>
#include <limits.h>
#include <math.h>
#include <s21_math.h>
#include <stdio.h>

START_TEST(zero) {
  double x;
  long double res;
  long double res21;

  x = 0.0;
  res = sqrt(x);
  res21 = s21_sqrt(x);
  ck_assert_ldouble_eq(res, res21);
  x = -0.0;
  res = sqrt(x);
  res21 = s21_sqrt(x);
  ck_assert_ldouble_eq(res, res21);
}
END_TEST

START_TEST(infinity) {
  double x;
  long double res;
  long double res21;

  x = INFINITY;
  res = sqrt(x);
  res21 = s21_sqrt(x);
  ck_assert_ldouble_infinite(res);
  ck_assert_ldouble_infinite(res21);

  x = -INFINITY;
  res = sqrt(x);
  res21 = s21_sqrt(x);
  ck_assert_ldouble_nan(res);
  ck_assert_ldouble_nan(res21);
}
END_TEST

START_TEST(not_a_number) {
  double x;
  long double res;
  long double res21;

  x = nan("");
  res = sqrt(x);
  res21 = s21_sqrt(x);
  ck_assert_ldouble_nan(res);
  ck_assert_ldouble_nan(res21);

  x = -nan("");
  res = sqrt(x);
  res21 = s21_sqrt(x);
  ck_assert_ldouble_nan(res);
  ck_assert_ldouble_nan(res21);
}
END_TEST

START_TEST(positive_double) {
  double x = 123.4;
  long double res = sqrt(x);
  long double res21 = s21_sqrt(x);
  ck_assert_ldouble_eq_tol(res, res21, 1e-6);
}
END_TEST

START_TEST(negative_double) {
  double x = -123.4;
  long double res = sqrt(x);
  long double res21 = s21_sqrt(x);
  ck_assert_ldouble_nan(res);
  ck_assert_ldouble_nan(res21);
}
END_TEST

static double nums1[] = {
    1.e-16,     1.e-15,      1.e-14,     1.e-12,   1.e-11,   1.e-10,
    1.e-9,      1.e-8,       2.3e-7,     1.4e-6,   1.89e-7,  5.12e-6,
    2.3e-5,     1.4e-4,      1.89e-3,    5.12e-2,  0.121218, 0.3733772,
    0.2884822,  0.521812883, 0.37172174, 0.618218, 0.746162, 0.831626121,
    0.99595848, FLT_MIN};

static size_t len1 = sizeof(nums1) / sizeof(double);

START_TEST(small_nums) {
  double num;
  long double res;
  long double res21;
  long double eps = 1.0e-6;

  for (size_t i = 0; i < len1; ++i) {
    num = nums1[i];
    res = sqrt(num);
    res21 = s21_sqrt(num);
    ck_assert_ldouble_eq_tol(res, res21, eps);
  }
}
END_TEST

static double nums2[] = {2,
                         4,
                         8,
                         16,
                         32,
                         64,
                         128,
                         256,
                         512,
                         1024,
                         9,
                         27,
                         625,
                         100000,
                         12721.2712721,
                         9559.271721,
                         36.3737,
                         1828289.282811,
                         966868694.5858494,
                         73831.182821,
                         218.1911,
                         10000.129291,
                         (double)INT_MAX,
                         (double)INT_MAX + 1.0,
                         (double)LONG_MAX,
                         (double)LONG_MAX + 1.0,
                         (double)ULONG_MAX,
                         (double)ULONG_MAX + 1.0,
                         (double)INT_MAX * 12.2281,
                         ((double)INT_MAX + 1.0) * 83.12710,
                         (double)LONG_MAX * 2.122,
                         ((double)LONG_MAX + 1.0) * 16.291,
                         (double)ULONG_MAX * 32.2181,
                         ((double)ULONG_MAX + 1.0) * 32.12721,
                         ((double)ULONG_MAX + 1.0) * 64.12721,
                         FLT_MAX};

static size_t len2 = sizeof(nums2) / sizeof(double);

START_TEST(nums) {
  double num;
  long double res;
  long double res21;
  long double eps = 1.0e-6;

  for (size_t i = 0; i < len2; ++i) {
    num = nums2[i];
    res = sqrt(num);
    res21 = s21_sqrt(num);
    ck_assert_ldouble_eq_tol(res, res21, eps);
  }
}
END_TEST

START_TEST(limits) {
  double num;
  long double res;
  long double res21;
  char str1[512];
  char str2[512];

  num = DBL_MAX;
  res = sqrt(num);
  res21 = s21_sqrt(num);
  sprintf(str1, "%Lf", res);
  sprintf(str2, "%Lf", res21);
  ck_assert(strncmp(str1, str2, 16) == 0);
}
END_TEST

Suite *suite_s21_sqrt(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_sqrt");
  tc = tcase_create("s21_sqrt tcase");

  if (s != NULL && tc != NULL) {
    tcase_add_test(tc, zero);
    tcase_add_test(tc, infinity);
    tcase_add_test(tc, not_a_number);
    tcase_add_test(tc, positive_double);
    tcase_add_test(tc, negative_double);
    tcase_add_test(tc, small_nums);
    tcase_add_test(tc, nums);
    tcase_add_test(tc, limits);
    suite_add_tcase(s, tc);
  }

  return (s);
}
