#ifndef S21_MATH_H
#define S21_MATH_H

#define S21_EPS 1e-16
#define S21_E 2.7182818284590452354
#define S21_LN2 0.69314718055994530942
#define S21_PI 3.141592653589793238462643383279
#define S21_MAX_DOUBLE 1.796794e+308
#define S21_INFINITY _s21_inf()
#define S21_NAN _s21_nan()
#define S21_DBL_EXP_OFFSET 1023
#define S21_DBL_MANT_BITS_COUNT 52
#define S21_DBL_EXP_BITS_COUNT 11

int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);

/* auxiary functions */
long double s21_trunc(double num);
int s21_isnan(double x);
int s21_isinf(double x);
float _s21_nan(void);
float _s21_inf(void);
long double _s21_integer_pow(double base, double e);
#endif
