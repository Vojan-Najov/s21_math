#ifndef TEST_MATH_H
#define TEST_MATH_H

#include <check.h>

#include "s21_math.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846 /* pi */
#endif
#ifndef M_PI_2
#define M_PI_2 1.57079632679489661923 /* pi/2 */
#endif
#ifndef M_PI_4
#define M_PI_4 0.78539816339744830962 /* pi/4 */
#endif

Suite *suite_s21_abs(void);
Suite *suite_s21_acos(void);
Suite *suite_s21_asin(void);
Suite *suite_s21_atan(void);
Suite *suite_s21_ceil(void);
Suite *suite_s21_cos(void);
Suite *suite_s21_exp(void);
Suite *suite_s21_fabs(void);
Suite *suite_s21_floor(void);
Suite *suite_s21_trunc(void);
Suite *suite_s21_fmod(void);
Suite *suite_s21_log(void);
Suite *suite_s21_pow(void);
Suite *suite_s21_sin(void);
Suite *suite_s21_sqrt(void);
Suite *suite_s21_isnan(void);
Suite *suite_s21_isinf(void);
Suite *suite_s21_tan(void);

#endif
