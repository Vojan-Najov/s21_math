#include "test_math.h"
#include <check.h>
#include <float.h>
#include <math.h>

#include "s21_math.h"

static double eps = 1.0e-36;

START_TEST(zero) {
  double x;
  double y;
  double ret;
  double ret21;

  x = 0.0;
  y = 0.0;
  ret = fmod(x, y);
  ret21 = s21_fmod(x, y);
  ck_assert_double_nan(ret);
  ck_assert_double_nan(ret21);
  x = 0.0;
  y = -0.0;
  ret = fmod(x, y);
  ret21 = s21_fmod(x, y);
  ck_assert_double_nan(ret);
  ck_assert_double_nan(ret21);

  x = 1.0;
  y = 0.0;
  ret = fmod(x, y);
  ret21 = s21_fmod(x, y);
  ck_assert_double_nan(ret);
  ck_assert_double_nan(ret21);
  x = 1.0;
  y = -0.0;
  ret = fmod(x, y);
  ret21 = s21_fmod(x, y);
  ck_assert_double_nan(ret);
  ck_assert_double_nan(ret21);
}
END_TEST

START_TEST(inf_nan) {
  double x;
  double y;
  double ret;
  double ret21;

  x = 1.0;
  y = nan("");
  ret = fmod(x, y);
  ret21 = s21_fmod(x, y);
  ck_assert_double_nan(ret);
  ck_assert_double_nan(ret21);
  x = 1.0;
  y = -nan("");
  ret = fmod(x, y);
  ret21 = s21_fmod(x, y);
  ck_assert_double_nan(ret);
  ck_assert_double_nan(ret21);
  x = nan("");
  y = 2.0;
  ret = fmod(x, y);
  ret21 = s21_fmod(x, y);
  ck_assert_double_nan(ret);
  ck_assert_double_nan(ret21);
  x = -nan("");
  y = 2.0;
  ret = fmod(x, y);
  ret21 = s21_fmod(x, y);
  ck_assert_double_nan(ret);
  ck_assert_double_nan(ret21);
  x = INFINITY;
  y = 2.0;
  ret = fmod(x, y);
  ret21 = s21_fmod(x, y);
  ck_assert_double_nan(ret);
  ck_assert_double_nan(ret21);
  x = -INFINITY;
  y = 2.0;
  ret = fmod(x, y);
  ret21 = s21_fmod(x, y);
  ck_assert_double_nan(ret);
  ck_assert_double_nan(ret21);
  x = 2.0;
  y = INFINITY;
  ret = fmod(x, y);
  ret21 = s21_fmod(x, y);
  ck_assert_double_eq(ret, ret21);
  x = INFINITY;
  y = INFINITY;
  ret = fmod(x, y);
  ret21 = s21_fmod(x, y);
  ck_assert_double_nan(ret);
  ck_assert_double_nan(ret21);
}
END_TEST

START_TEST(equal) {
  double x = 1234.21213;
  double y = 1234.21213;
  double ret;
  double ret21;

  ret = fmod(x, y);
  ret21 = s21_fmod(x, y);
  ck_assert_double_eq(ret, ret21);
}
END_TEST

START_TEST(kratno) {
  double x = 1234.21213 * 20;
  double y = 1234.21213;
  double ret;
  double ret21;

  ret = fmod(x, y);
  ret21 = s21_fmod(x, y);
  ck_assert_double_eq(ret, ret21);
}
END_TEST

static double nums_negative[] = {-11.9888,
                                 -25.3570,
                                 -13.0675,
                                 -44.5435,
                                 -5.4645,
                                 -309457389.324234,
                                 -24658936.2347239847,
                                 -0.1,
                                 -1.0e-2,
                                 -3.0e-4,
                                 -4.0e-5,
                                 -6.0e-6,
                                 -0.011221,
                                 -M_PI_2,
                                 -M_PI,
                                 -2 * M_PI,
                                 -M_PI / 2.0,
                                 -3.0 / 2.0 * M_PI,
                                 -4.0 * M_PI,
                                 -5 / 2 * M_PI,
                                 -7.4747e10,
                                 -1.2828182e14,
                                 -122.21821712721712712721e11,
                                 -9.999999999e13,
                                 -2.0,
                                 -1.0,
                                 -1.5,
                                 -3.0};

static double len_negative = sizeof(nums_negative) / sizeof(double);

static double nums_positive[] = {5.17657,
                                 7.578678,
                                 7.43543457,
                                 2.78987,
                                 10.54343256,
                                 3467.2847293,
                                 2347894.23423239,
                                 0.1,
                                 1.0e-2,
                                 3.0e-4,
                                 4.0e-5,
                                 6.0e-6,
                                 0.011221,
                                 M_PI,
                                 M_PI_2,
                                 2 * M_PI,
                                 M_PI / 2.0,
                                 3.0 / 2.0 * M_PI,
                                 4.0 * M_PI,
                                 5 / 2 * M_PI,
                                 7.4747e10,
                                 1.2828182e14,
                                 122.21821712721712712721e11,
                                 9.999999999e13,
                                 2.0,
                                 1.0,
                                 1.5,
                                 3.0};
static double len_positive = sizeof(nums_positive) / sizeof(double);

START_TEST(nums_1) {
  double num_x;
  double num_y;
  double ret;
  double ret21;

  for (size_t i = 0; i < len_negative; i++) {
    for (size_t j = 0; j < len_positive; j++) {
      num_x = nums_positive[i];
      num_y = nums_positive[j];
      ret = fmod(num_x, num_y);
      ret21 = s21_fmod(num_x, num_y);
      ck_assert_double_eq_tol(ret, ret21, eps);
    }
  }
}
END_TEST

START_TEST(nums_2) {
  double num_x;
  double num_y;
  double ret;
  double ret21;

  for (size_t i = 0; i < len_negative; i++) {
    for (size_t j = 0; j < len_positive; j++) {
      num_x = nums_positive[i];
      num_y = nums_negative[j];
      ret = fmod(num_x, num_y);
      ret21 = s21_fmod(num_x, num_y);
      ck_assert_double_eq_tol(ret, ret21, eps);
    }
  }
}
END_TEST

START_TEST(nums_3) {
  double num_x;
  double num_y;
  double ret;
  double ret21;

  for (size_t i = 0; i < len_negative; i++) {
    for (size_t j = 0; j < len_positive; j++) {
      num_x = nums_negative[i];
      num_y = nums_positive[j];
      ret = fmod(num_x, num_y);
      ret21 = s21_fmod(num_x, num_y);
      ck_assert_double_eq_tol(ret, ret21, eps);
    }
  }
}
END_TEST

START_TEST(nums_4) {
  double num_x;
  double num_y;
  double ret;
  double ret21;

  for (size_t i = 0; i < len_negative; i++) {
    for (size_t j = 0; j < len_positive; j++) {
      num_x = nums_negative[i];
      num_y = nums_negative[j];
      ret = fmod(num_x, num_y);
      ret21 = s21_fmod(num_x, num_y);
      ck_assert_double_eq_tol(ret, ret21, eps);
    }
  }
}
END_TEST

START_TEST(positive_PI) {
  double x = +S21_PI;
  double y = 1.0;
  double ret;
  double ret21;

  ret = fmod(x, y);
  ret21 = s21_fmod(x, y);
  ck_assert_double_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(positive_PI_1_2) {
  double x = +S21_PI / 2;
  double y = 1.0;
  double ret;
  double ret21;

  ret = fmod(x, y);
  ret21 = s21_fmod(x, y);
  ck_assert_double_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(positive_2_PI) {
  double x = +S21_PI * 2;
  double y = 1.0;
  double ret;
  double ret21;

  ret = fmod(x, y);
  ret21 = s21_fmod(x, y);
  ck_assert_double_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(positive_2_PI_3) {
  double x = +S21_PI * 2 / 3;
  double y = 1.0;
  double ret;
  double ret21;

  ret = fmod(x, y);
  ret21 = s21_fmod(x, y);
  ck_assert_double_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(positive_PI_1_4) {
  double x = +S21_PI / 4;
  double y = 1.0;
  double ret;
  double ret21;

  ret = fmod(x, y);
  ret21 = s21_fmod(x, y);
  ck_assert_double_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(positive_PI_3_4) {
  double x = +S21_PI * 3 / 4;
  double y = 1.0;
  double ret;
  double ret21;

  ret = fmod(x, y);
  ret21 = s21_fmod(x, y);
  ck_assert_double_eq_tol(ret, ret21, eps);
}
END_TEST
START_TEST(negative_PI) {
  double x = -S21_PI;
  double y = 1.0;
  double ret;
  double ret21;

  ret = fmod(x, y);
  ret21 = s21_fmod(x, y);
  ck_assert_double_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(negative_PI_1_2) {
  double x = -S21_PI / 2;
  double y = 1.0;
  double ret;
  double ret21;

  ret = fmod(x, y);
  ret21 = s21_fmod(x, y);
  ck_assert_double_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(negative_2_PI) {
  double x = -S21_PI * 2;
  double y = 1.0;
  double ret;
  double ret21;

  ret = fmod(x, y);
  ret21 = s21_fmod(x, y);
  ck_assert_double_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(negative_2_PI_3) {
  double x = -S21_PI * 2 / 3;
  double y = 1.0;
  double ret;
  double ret21;

  ret = fmod(x, y);
  ret21 = s21_fmod(x, y);
  ck_assert_double_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(negative_PI_1_4) {
  double x = -S21_PI * 4;
  double y = 1.0;
  double ret;
  double ret21;

  ret = fmod(x, y);
  ret21 = s21_fmod(x, y);
  ck_assert_double_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(negative_PI_3_4) {
  double x = -S21_PI * 3 / 4;
  double y = 1.0;
  double ret;
  double ret21;

  ret = fmod(x, y);
  ret21 = s21_fmod(x, y);
  ck_assert_double_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(positive_S21_MAX_DOUBLE) {
  double x = +S21_MAX_DOUBLE;
  double y = 1.0;
  double ret;
  double ret21;

  ret = fmod(x, y);
  ret21 = s21_fmod(x, y);
  ck_assert_double_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(positive_dbl_min) {
  double x = +DBL_MIN;
  double y = 1.0;
  double ret;
  double ret21;

  ret = fmod(x, y);
  ret21 = s21_fmod(x, y);
  ck_assert_double_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(negative_dbl_min) {
  double x = -DBL_MIN;
  double y = 1.0;
  double ret;
  double ret21;

  ret = fmod(x, y);
  ret21 = s21_fmod(x, y);
  ck_assert_double_eq_tol(ret, ret21, eps);
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
}
END_TEST

Suite *suite_s21_fmod(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_fmod");
  tc = tcase_create("s21_fmod tcase");

  if (s != NULL && tc != NULL) {
    tcase_add_test(tc, zero);
    tcase_add_test(tc, inf_nan);
    tcase_add_test(tc, equal);
    tcase_add_test(tc, kratno);
    tcase_add_test(tc, nums_1);
    tcase_add_test(tc, nums_2);
    tcase_add_test(tc, nums_3);
    tcase_add_test(tc, nums_4);
    tcase_add_test(tc, positive_PI);
    tcase_add_test(tc, positive_PI_1_2);
    tcase_add_test(tc, positive_2_PI);
    tcase_add_test(tc, positive_2_PI_3);
    tcase_add_test(tc, positive_PI_1_4);
    tcase_add_test(tc, positive_PI_3_4);
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
