#include <check.h>
#include <math.h>

#include "s21_math.h"

static double b[] = {-1.0, 1.0,  0.0, -0.0, 2.0,  -2.0, -2.5,
                     2.5,  -0.5, 0.5, 10.0, 10.3, 20.0};

static double e[] = {-1.0, 1.0,  0.0,  -0.0,  2.0,  -2.0, 10.0,
                     13.0, 20.0, 15.0, -15.0, 11.0, -7.0, 7.0};

START_TEST(test) {
  long double ret, ret21;

  for (size_t i = 0; i < sizeof(b) / sizeof(double); ++i) {
    for (size_t j = 0; j < sizeof(e) / sizeof(double); ++j) {
      ret = pow(b[i], e[j]);
      ret21 = _s21_integer_pow(b[i], e[j]);
      if (s21_isinf(ret)) {
        ck_assert_ldouble_eq(ret, ret21);
      } else if (ret > 1.0e9) {
        ck_assert_ldouble_eq_tol(ret, ret21, 1.e-16 * ret);
      } else {
        ck_assert_ldouble_eq_tol(ret, ret21, 1.0e-6);
      }
    }
  }
}
END_TEST

Suite *suite_s21_pow_aux(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_pow_aux");
  tc = tcase_create("s21_pow_aux tcase");

  if (s != NULL && tc != NULL) {
    tcase_add_test(tc, test);
    suite_add_tcase(s, tc);
  }

  return (s);
}
