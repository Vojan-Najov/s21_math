#include <check.h>
#include <float.h>
#include <math.h>
#include <stdio.h>

#include "s21_math.h"

START_TEST(unit) {
  long double num;
  long double ret;
  long double ret21;

  num = 1.0;
  ret = exp(num);
  ret21 = s21_exp(num);
  ck_assert_ldouble_eq_tol(ret, ret21, 1e-6);
  num = -1.0;
  ret = exp(num);
  ret21 = s21_exp(num);
  ck_assert_ldouble_eq_tol(ret, ret21, 1e-6);
}
END_TEST

START_TEST(zero) {
  long double num;
  long double ret;
  long double ret21;

  num = 0.0;
  ret = exp(num);
  ret21 = s21_exp(num);
  ck_assert_ldouble_eq_tol(ret, ret21, 1e-6);
  num = -0.0;
  ret = exp(num);
  ret21 = s21_exp(num);
  ck_assert_ldouble_eq_tol(ret, ret21, 1e-6);
}
END_TEST

static double neg_nums[] = {-16564, -178,  -30,   -10,        -1.5,
                            -1.125, -1.01, -0.95, -0.765,     -0.5,
                            -0.125, -0.1,  -0.05, -0.00012311};
static double neg_num_len = sizeof(neg_nums) / sizeof(double);

START_TEST(test_negative_nums) {
  double num;
  long double ret;
  long double ret21;
  int precision = 6;

  for (size_t i = 0; i < neg_num_len; ++i) {
    num = neg_nums[i];
    ret = exp(num);
    ret21 = s21_exp(num);
    if (fabsl(ret - ret21) >= 1e-6) {
      printf("num = %f\n", neg_nums[i]);
      printf("precision = %f\n", pow(10, -precision));
      printf("exp    : %.8Lf\n", ret);
      printf("s21_exp: %.8Lf\n", ret21);
    }
    ck_assert_ldouble_eq_tol(ret, ret21, 1.0e-6);
  }
}
END_TEST

static double pos_nums[] = {
    600.29112, 500,   300.3838, 200.12188, 178, 30,    16.121,
    12.456,    10,    5.9281,   4.8471,    1.5, 1.125, 1.01,
    0.95,      0.765, 0.5,      0.125,     0.1, 0.05,
};
static double pos_num_len = sizeof(pos_nums) / sizeof(double);

START_TEST(test_positive_nums) {
  double num;
  long double ret;
  long double ret21;
  int precision = 6;

  for (size_t i = 0; i < pos_num_len; ++i) {
    num = pos_nums[i];
    ret = exp(num);
    ret21 = s21_exp(num);
    if (ret > 1.0) {
      int count_int_digits = 0;
      for (long double n = ret; n > 1.0; n /= 10.0) {
        ++count_int_digits;
      }
      if (16 - count_int_digits < 6) {
        precision = 16 - count_int_digits;
      }
    }

    if (fabsl(ret - ret21) >= pow(10, -precision)) {
      printf("num = %f\n", pos_nums[i]);
      printf("precision = %f\n", pow(10, -precision));
      printf("exp    : %.8Lf\n", ret);
      printf("s21_exp: %.8Lf\n", ret21);
    }
    ck_assert_ldouble_eq_tol(ret, ret21, pow(10, -precision));
  }
}
END_TEST

START_TEST(result_is_inf_1) {
  double num;
  long double ret;
  long double ret21;

  num = 2000.0;
  ret = exp(num);
  ret21 = s21_exp(num);
  ck_assert_double_infinite(ret);
  ck_assert_ldouble_infinite(ret21);
  num = 900.0;
  ret = exp(num);
  ret21 = s21_exp(num);
  ck_assert_double_infinite(ret);
  ck_assert_ldouble_infinite(ret21);
}
END_TEST

START_TEST(result_is_inf_2) {
  double num;
  long double ret;
  long double ret21;

  num = 5000.0;
  ret = exp(num);
  ret21 = s21_exp(num);
  ck_assert_double_infinite(ret);
  ck_assert_ldouble_infinite(ret21);
  num = 10000.0;
  ret = exp(num);
  ret21 = s21_exp(num);
  ck_assert_double_infinite(ret);
  ck_assert_ldouble_infinite(ret21);
}
END_TEST

START_TEST(result_is_inf_3) {
  double num;
  long double ret;
  long double ret21;

  num = 16000.0;
  ret = exp(num);
  ret21 = s21_exp(num);
  ck_assert_double_infinite(ret);
  ck_assert_ldouble_infinite(ret21);
  num = 18911.0;
  ret = exp(num);
  ret21 = s21_exp(num);
  ck_assert_double_infinite(ret);
  ck_assert_ldouble_infinite(ret21);
}
END_TEST

START_TEST(result_near_zero) {
  double num;
  long double ret;
  long double ret21;

  num = -20;
  ret = exp(num);
  ret21 = s21_exp(num);
  if (fabsl(ret - ret21) >= 1e-6) {
    printf("num = %f\n", num);
    printf("exp    : %.8Lf\n", ret);
    printf("s21_exp: %.8Lf\n", ret21);
  }
  ck_assert_ldouble_eq_tol(ret, ret21, 1e-6);
  ck_assert_ldouble_eq_tol(ret, ret21, 1e-6);
  num = -100.0;
  ret = exp(num);
  ret21 = s21_exp(num);
  if (fabsl(ret - ret21) >= 1e-6) {
    printf("num = %f\n", num);
    printf("exp    : %.8Lf\n", ret);
    printf("s21_exp: %.8Lf\n", ret21);
  }
  ck_assert_ldouble_eq_tol(ret, ret21, 1e-6);
  ck_assert_ldouble_eq_tol(ret, ret21, 1e-6);
  num = -1000.0;
  ret = exp(num);
  ret21 = s21_exp(num);
  if (fabsl(ret - ret21) >= 1e-6) {
    printf("num = %f\n", num);
    printf("exp    : %.8Lf\n", ret);
    printf("s21_exp: %.8Lf\n", ret21);
  }
  ck_assert_ldouble_eq_tol(ret, ret21, 1e-6);
  ck_assert_ldouble_eq_tol(ret, ret21, 1e-6);
  num = -4000.212;
  ret = expl(num);
  ret21 = s21_exp(num);
  ck_assert_ldouble_eq_tol(ret, ret21, 1e-6);
  num = -20000.12121;
  ret = expl(num);
  ret21 = s21_exp(num);
  ck_assert_ldouble_eq_tol(ret, ret21, 1e-6);
  ck_assert_ldouble_eq_tol(ret, ret21, 1e-6);
  ck_assert_ldouble_eq_tol(ret, ret21, 1e-6);
}
END_TEST

START_TEST(special) {
  long double num;
  long double ret;
  long double ret21;

  num = nan("");
  ret = exp(num);
  ret21 = s21_exp(num);
  ck_assert_ldouble_nan(ret);
  ck_assert_ldouble_nan(ret21);
  num = 65000.0;
  ret = exp(num);
  ret21 = s21_exp(num);
  ck_assert_ldouble_infinite(ret);
  ck_assert_ldouble_infinite(ret21);
  num = -65000.0;
  ret = exp(num);
  ret21 = s21_exp(num);
  ck_assert_ldouble_eq(ret, ret21);
}
END_TEST

START_TEST(cycle) {
  long double ret;
  long double ret21;
  char buf1[1024 * 8];
  char buf2[1024 * 8];

  for (double i = -100; i < 100; i += 0.1) {
    ret = exp(i);
    ret21 = s21_exp(i);
    if (ret >= 1e16) {
      continue;
      sprintf(buf1, "%Lf\n", ret);
      sprintf(buf2, "%Lf\n", ret21);
      if (strncmp(buf1, buf2, 16)) {
        printf("%f\n", i);
        printf("%.16s\n%.16s\n\n", buf1, buf2);
      }
      ck_assert(strncmp(buf1, buf2, 16) == 0);
    } else if (ret >= 1e15) {
      ck_assert_ldouble_eq_tol(ret, ret21, 1e-1);
    } else if (ret >= 1e14) {
      ck_assert_ldouble_eq_tol(ret, ret21, 1e-2);
    } else if (ret >= 1e13) {
      ck_assert_ldouble_eq_tol(ret, ret21, 1e-3);
    } else if (ret >= 1e12) {
      ck_assert_ldouble_eq_tol(ret, ret21, 1e-4);
    } else if (ret >= 1e11) {
      ck_assert_ldouble_eq_tol(ret, ret21, 1e-5);
    } else {
      ck_assert_ldouble_eq_tol(ret, ret21, 1e-6);
    }
  }
}

Suite *suite_s21_exp(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_exp");
  tc = tcase_create("s21_exp");

  if (s != NULL && tc != NULL) {
    tcase_add_test(tc, unit);
    tcase_add_test(tc, zero);
    tcase_add_test(tc, test_negative_nums);
    tcase_add_test(tc, test_positive_nums);
    tcase_add_test(tc, result_is_inf_1);
    tcase_add_test(tc, result_is_inf_2);
    tcase_add_test(tc, result_is_inf_3);
    tcase_add_test(tc, result_near_zero);
    tcase_add_test(tc, special);
    tcase_add_test(tc, cycle);
    suite_add_tcase(s, tc);
  }

  return (s);
}
