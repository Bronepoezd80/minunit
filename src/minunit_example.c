/**
 * Jakob Janzen
 * jakob.janzen80@gmail.com
 * 2022-09-24
 *
 * minunit_example.c
 */
#include <stdio.h>
#include <stdlib.h>

#include "minunit.h"

int
test1(void)
{
  MU_ASSERT(3 == 3);
  return EXIT_SUCCESS;
}

int
test2(void)
{
  MU_ASSERT((double)3.3 == (double)3.3);
  return EXIT_SUCCESS;
}

int
test3(void)
{
  MU_ASSERT('i' == 'i');
  return EXIT_SUCCESS;
}

int
test4(void)
{
  MU_ASSERT(6 == 5);
  return EXIT_SUCCESS;
}

int
all_tests(void)
{
  MU_RUN_TEST(test1);
  MU_RUN_TEST(test2);
  MU_RUN_TEST(test3);
  MU_RUN_TEST(test4);
  return EXIT_SUCCESS;
}

int
main(void)
{
  int result = all_tests();
  MU_RESULT();

  return result;
}
