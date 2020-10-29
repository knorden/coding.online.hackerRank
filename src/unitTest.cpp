#include "unitTest.hpp"

using namespace std;

vector<string> findStrings(vector<string> w, vector<int> queries);

bool unitTestFunc() {
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
  vector<string> w = {"aab", "aac"};
  vector<int> q = {3, 8, 23};
  vector<string> out = findStrings(w, q);
  for (auto i : out) {
    std::cout << i << endl;
  }
  return allPassed;
}

vector<string> findStrings(vector<string> w, vector<int> queries) {
  vector<vector<char>> vec_charvec;
  vector<char>* str = nullptr;
  for (auto i : w) {
    str = new vector<char>;
    for (auto j : i) {
      str->push_back(j);
    }
    vec_charvec.push_back(*str);
    delete str;
  }
  vector<vector<string>> new_w;
  string temp;
  int vec_size = vec_charvec.size();
  for (int i = 0; i < vec_size; ++i) {
    int cv_size = vec_charvec[i].size();
    temp = "";
    vector<string> vect;
    for (int j = 0; j < cv_size; ++j) {
      temp = "";
      for (int k = j; k < cv_size; ++k) {
        temp += vec_charvec[i][k];
        bool dup = false;
        for (auto l : vect) {
          if (temp == l) {
            continue;
          }
        }
        vect.push_back(temp);
      }
    }
    new_w.push_back(vect);
  }

  vector<string> real_w;
  for (auto i : new_w[0]) {
    bool dup = false;
    for (auto j : real_w) {
      if (j == i) {
        dup = true;
        break;
      }
    }
    if (dup == true) continue;
    real_w.push_back(i);
  }

  for (int i = 1; i < new_w.size(); ++i) {
    for (auto j : real_w) {
      vector<string> tempst;
      for (auto k : new_w[i]) {
        if (j == k) {
          continue;
        }
        tempst.push_back(k);
      }
      for (auto k : tempst) {
        bool dup = false;
        for (auto l : real_w) {
          if (l == k) {
            dup = true;
            break;
          }
        }
        if (dup == true)
          continue;
        else
          real_w.push_back(k);
      }
    }
  }
  int longest_str = 0;
  for (auto i : w) {
    if (i.size() > longest_str) longest_str = i.size();
  }

  vector<string> ordered_w;
  int unique_indx = 0;
  for (int i = 1; i <= longest_str; ++i) {
    if (i == 2) unique_indx = ordered_w.size() - 1;
    for (auto j : real_w) {
      if (j.size() == i) ordered_w.push_back(j);
    }
  }

  vector<string> unq_c;
  for (int i = 0; i <= unique_indx; ++i) {
    unq_c.push_back(ordered_w[i]);
  }

  vector<string> output;

  // for (int i = 0; i < queries.size(); ++i) {
  //   int j = queries[i];
  //   if (j >= new_w.size())
  //     output.push_back("INVALID");
  //   else
  //     output.push_back(new_w[j]);
  // }
  return output;
} 