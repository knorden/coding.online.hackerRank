#include "_Test.hpp"

bool TestWrapper() {
  /* VARIABLE FOR UNIT TESTS: test-id, test-name, pass/fail-check */
  static Test thisTest;
  static bool allPassed = true;

  /*******************************************************************************/
  thisTest.Name = "INIT OUTPUT";
  TestHeader(thisTest);
  /*******************************************************************************/
  /* TEST_BODY STARTS BELOW */
  allPassed = []() {
    std::string tString = "THIS IS A TEST STRING.";
    std::cout << tString;
    return true;
  }();
  errCatch(allPassed, thisTest);

  /*******************************************************************************/
  thisTest.Name = " ";
  TestHeader(thisTest);
  /*******************************************************************************/
  /* TEST_BODY STARTS BELOW */

  return allPassed;
}