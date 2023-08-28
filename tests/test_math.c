#include "test_math.h"

#include <check.h>
#include <stdlib.h>

static int run_test_suite(Suite *test_suite) {
  int number_failed = 0;
  SRunner *sr = NULL;

  sr = srunner_create(test_suite);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed);
}

int main(void) {
  int number_failed = 0;
  Suite *suite_array[] = {suite_s21_abs(),     suite_s21_acos(),
                          suite_s21_asin(),    suite_s21_atan(),
                          suite_s21_ceil(),    suite_s21_cos(),
                          suite_s21_exp(),     suite_s21_fabs(),
                          suite_s21_floor(),   suite_s21_fmod(),
                          suite_s21_pow(),     suite_s21_log(),
                          suite_s21_sin(),     suite_s21_sqrt(),
                          suite_s21_tan(),     suite_s21_trunc(),
                          suite_s21_isnan(),   suite_s21_isinf(),
                          suite_s21_pow_aux(), NULL};

  for (size_t i = 0; suite_array[i]; ++i) {
    number_failed += run_test_suite(suite_array[i]);
  }

  return (number_failed ? EXIT_FAILURE : EXIT_SUCCESS);
}
