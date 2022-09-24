/**
 * Jakob Janzen
 * jakob.janzen80@gmail.com
 * 2021-05-23
 *
 * minunit.h
 */
#ifndef __MU_MINUNIT_H__
#define __MU_MINUNIT_H__

#ifdef __cplusplus
#include <cstdio>
#include <cstdlib>
#else
#include <stdio.h>
#include <stdlib.h>
#endif

#ifdef __cplusplus
extern "C"
{
#endif

/*
basename - return the last component of a pathname
#include <libgen.h>
char *basename(char *path);
*/
#include <libgen.h>

  //__attribute__((unused)) static int test_run=0;
  extern int tests_run;
  int tests_run = 0;

#define MU_PASSED(assertion_)                                                  \
  do {                                                                         \
    char* __file = basename((char*)__FILE__);                                  \
    fprintf(stdout,                                                            \
            "[PASS] file: %s, line: %d: " #assertion_ "\n",                    \
            __file,                                                            \
            __LINE__);                                                         \
  } while (0)

#define MU_FAILED(assertion_)                                                  \
  do {                                                                         \
    char* __file = basename((char*)__FILE__);                                  \
    fprintf(stdout,                                                            \
            "[FAILED] file: %s, line: %d: " #assertion_ "\n",                  \
            __file,                                                            \
            __LINE__);                                                         \
  } while (0)

#define MU_ASSERT(test_)                                                       \
  do {                                                                         \
    if (!(test_)) {                                                            \
      MU_FAILED(test_);                                                        \
      return EXIT_FAILURE;                                                     \
    };                                                                         \
    MU_PASSED(test_);                                                          \
  } while (0)

#define MU_RUN_TEST(test_func_)                                                \
  do {                                                                         \
    tests_run++;                                                               \
    if (test_func_() == EXIT_FAILURE)                                          \
      return EXIT_FAILURE;                                                     \
  } while (0)

#define MU_RESULT()                                                            \
  do {                                                                         \
    fprintf(stdout, "Tests run: %d\n", tests_run);                             \
  } while (0)

#ifdef __cplusplus
}
#endif

#endif /* __MU_MINUNIT_H__ */
