#include <check.h>
#include <float.h>
#include <math.h>

#include "s21_math.h"

static double nums[] = {
    -1.0,     -1.1,     -10.0,   -11.9888,          -25.3570,
    -13.0675, -44.5435, -5.4645, -309457389.324234, -24658936.2347239847,
    1.0,      1.1,      10.0,    11.9888,           25.3570,
    13.0675,  44.5435,  5.4645,  309457389.324234};

static double nums_len = sizeof(nums) / sizeof(double);

START_TEST(dbl_nums) {
  double num;
  double ret;
  double ret21;

  for (size_t j = 0; j < nums_len; j++) {
    num = nums[j];
    ret = floor(num);
    ret21 = s21_floor(num);
    ck_assert_double_eq(ret, ret21);
  }
}
END_TEST

START_TEST(inf_nan) {
  double x;
  double ret;
  double ret21;

  x = INFINITY;
  ret = floor(x);
  ret21 = s21_floor(x);
  ck_assert_double_eq(ret, ret21);
  x = -INFINITY;
  ret = floor(x);
  ret21 = s21_floor(x);
  ck_assert_double_eq(ret, ret21);
  x = nan("");
  ret = floor(x);
  ret21 = s21_floor(x);
  ck_assert_double_nan(ret);
  ck_assert_double_nan(ret21);
  x = -nan("");
  ret = floor(x);
  ret21 = s21_floor(x);
  ck_assert_double_nan(ret);
  ck_assert_double_nan(ret21);
}
END_TEST

START_TEST(zero) {
  double x;
  double ret;
  double ret21;

  x = 0.0;
  ret = floor(x);
  ret21 = s21_floor(x);
  ck_assert_double_eq(ret, ret21);
  x = -0.0;
  ret = floor(x);
  ret21 = s21_floor(x);
  ck_assert_double_eq(ret, ret21);
}
END_TEST

START_TEST(positive_PI) {
  double x = +S21_PI;
  double ret;
  double ret21;

  ret = floor(x);
  ret21 = s21_floor(x);
  ck_assert_double_eq(ret, ret21);
}
END_TEST

START_TEST(positive_PI_1_2) {
  double x = +S21_PI / 2;
  double ret;
  double ret21;

  ret = floor(x);
  ret21 = s21_floor(x);
  ck_assert_double_eq(ret, ret21);
}
END_TEST

START_TEST(positive_2_PI) {
  double x = +S21_PI * 2;
  double ret;
  double ret21;

  ret = floor(x);
  ret21 = s21_floor(x);
  ck_assert_double_eq(ret, ret21);
}
END_TEST

START_TEST(positive_2_PI_3) {
  double x = +S21_PI * 2 / 3;
  double ret;
  double ret21;

  ret = floor(x);
  ret21 = s21_floor(x);
  ck_assert_double_eq(ret, ret21);
}
END_TEST

START_TEST(positive_PI_1_4) {
  double x = +S21_PI / 4;
  double ret;
  double ret21;

  ret = floor(x);
  ret21 = s21_floor(x);
  ck_assert_double_eq(ret, ret21);
}
END_TEST

START_TEST(positive_PI_3_4) {
  double x = +S21_PI * 3 / 4;
  double ret;
  double ret21;

  ret = floor(x);
  ret21 = s21_floor(x);
  ck_assert_double_eq(ret, ret21);
}
END_TEST

START_TEST(negative_PI) {
  double x = -S21_PI;
  double ret;
  double ret21;

  ret = floor(x);
  ret21 = s21_floor(x);
  ck_assert_double_eq(ret, ret21);
}
END_TEST

START_TEST(negative_PI_1_2) {
  double x = -S21_PI / 2;
  double ret;
  double ret21;

  ret = floor(x);
  ret21 = s21_floor(x);
  ck_assert_double_eq(ret, ret21);
}
END_TEST

START_TEST(negative_2_PI) {
  double x = -S21_PI * 2;
  double ret;
  double ret21;

  ret = floor(x);
  ret21 = s21_floor(x);
  ck_assert_double_eq(ret, ret21);
}
END_TEST

START_TEST(negative_2_PI_3) {
  double x = -S21_PI * 2 / 3;
  double ret;
  double ret21;

  ret = floor(x);
  ret21 = s21_floor(x);
  ck_assert_double_eq(ret, ret21);
}
END_TEST

START_TEST(negative_PI_1_4) {
  double x = -S21_PI * 4;
  double ret;
  double ret21;

  ret = floor(x);
  ret21 = s21_floor(x);
  ck_assert_double_eq(ret, ret21);
}
END_TEST

START_TEST(negative_PI_3_4) {
  double x = -S21_PI * 3 / 4;
  double ret;
  double ret21;

  ret = floor(x);
  ret21 = s21_floor(x);
  ck_assert_double_eq(ret, ret21);
}
END_TEST

START_TEST(dbl_limits) {
  double x;
  double ret;
  double ret21;

  x = -FLT_MIN;
  ret = floor(x);
  ret21 = s21_floor(x);
  ck_assert_double_eq(ret, ret21);
  x = FLT_MIN;
  ret = floor(x);
  ret21 = s21_floor(x);
  ck_assert_double_eq(ret, ret21);
  x = -FLT_MAX;
  ret = floor(x);
  ret21 = s21_floor(x);
  ck_assert_double_eq(ret, ret21);
  x = FLT_MAX;
  ret = floor(x);
  ret21 = s21_floor(x);
  ck_assert_double_eq(ret, ret21);
  x = -DBL_MIN;
  ret = floor(x);
  ret21 = s21_floor(x);
  ck_assert_double_eq(ret, ret21);
  x = DBL_MIN;
  ret = floor(x);
  ret21 = s21_floor(x);
  ck_assert_double_eq(ret, ret21);
  x = -DBL_MAX;
  ret = floor(x);
  ret21 = s21_floor(x);
  ck_assert_double_eq(ret, ret21);
  x = DBL_MAX;
  ret = floor(x);
  ret21 = s21_floor(x);
  ck_assert_double_eq(ret, ret21);
}
END_TEST

Suite *suite_s21_floor(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_floor");
  tc = tcase_create("s21_floor tcase");

  if (s != NULL && tc != NULL) {
    tcase_add_test(tc, dbl_nums);
    tcase_add_test(tc, zero);
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
    tcase_add_test(tc, dbl_limits);
    tcase_add_test(tc, inf_nan);
    suite_add_tcase(s, tc);
  }

  return (s);
}
