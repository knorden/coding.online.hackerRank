#include "easy02.hpp"

using namespace std;
/******************************************************************************
 * PROBLEM: GRADING STUDENTS
 * ---------------------------------------------------------------------------
 * Goal: rounding grades based on conditions:
 * 1. If the difference between the <grade> and the next multiple of 5 is
 *    less than 3, round up to the next multiple of 5.
 * 2. If the <grade> less than 38: no rounding, failing grade.
 *
 ******************************************************************************/
/******************************************************************************
 * SOLUTION:
 * First: set up the algorithm to check for rounding elgibility.
 *  - Rounded % 5 = 0, therefore:
 *      If (any_n % 5 != 0) get its quotient and add 1 to get the rounded.
 *        rounded = (any_n / 5) + 1
 *          If(any_num < 40) push the number unchanged to vector
 *          Otherwise:
 *          If (rounded - any_num < 3) push the rounded to the result_vector
 *
 ******************************************************************************/
std::vector<int> gradingStudents(std::vector<int> grades) {
  vector<int> results;
  int rounded;
  const int FAILING = 40;
  for (auto i : grades) {
    if (i % 5 != 0) {
      rounded = 5 * (i / 5 + 1);
      if (rounded < FAILING)
        results.push_back(i);
      else {
        if (rounded - i < 3)
          results.push_back(rounded);
        else
          results.push_back(i);
      }
    } else
      results.push_back(i);
  }

  return results;
}