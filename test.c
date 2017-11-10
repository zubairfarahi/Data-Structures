#include <stdio.h>
#include "solve.h"

#define ASSERT(cond, msg) if (!(cond)) { failed(msg); } else { passed(msg); }

void passed(char *s) {
  printf("Test %s passed successfully!\t\t \n", s);
}

void failed(char *s) {
  printf("Test %s NOT passed!\n", s);
}

void runTest(char *testInputFileName, int expectedCost, char *testName) {
  ASSERT(solve(testInputFileName) == expectedCost, testName);
}

int main() {
  runTest("test1.in", 50, "Test 1");
  runTest("test2.in", 330, "Test 2");
  runTest("test3.in", 33, "Test 3");
  runTest("test4.in", 22, "Test 4");
  runTest("test5.in", 72, "Test 5");
  runTest("test6.in", 244, "Test 6");
  runTest("test7.in", 376, "Test 7");
  runTest("test8.in", 389, "Test 8");
  runTest("test9.in", 256, "Test 9");
  runTest("test10.in", 1619, "Test 10");

  return 0;
}
