/**
 * Jakob Janzen
 * jakob.janzen80@gmail.com
 * 2021-05-23
 *
 * minunit_example.cxx
 */
#include <cstdio>
#include <cstdlib>

#include <iostream>
#include <string>
#include <vector>

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
  std::vector<std::string> v{ "aaa", "aaa" };
  MU_ASSERT(v[0] == v[1]);
  return EXIT_SUCCESS;
}

int
test3(void)
{
  MU_ASSERT(std::string("abc") == std::string("abc"));
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
