#include <flex2d/vector.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdarg.h>
#include <cmocka.h>
#include <math.h>
#include <stdlib.h>

void test_vector_non_null(void **state)
{
  Vector *v = vector_new(0, 0);
  assert_non_null(v);
}

void test_vector_distance_squared(void **state)
{
  double x = 10.0, y = 10.0;
  Vector *v = vector_new(x, y);
  double distance = x*x + y*y;
  double epsilon = 1.0e-9;
  assert_float_equal(vector_distance_squared(v), distance, epsilon);
}

void test_vector_distance(void **state)
{
  double x = 10.0, y = 10.0;
  Vector *v = vector_new(x, y);
  double distance = sqrt(x*x + y*y);
  double epsilon = 1.0e-9;
  assert_float_equal(vector_distance(v), distance, epsilon);
}

int main(void)
{
  const struct CMUnitTest tests[] = {
	 cmocka_unit_test(test_vector_non_null),
	 cmocka_unit_test(test_vector_distance),
	 cmocka_unit_test(test_vector_distance_squared)
  };

  int failed_tests = cmocka_run_group_tests(tests, NULL, NULL);

  return failed_tests;
}
