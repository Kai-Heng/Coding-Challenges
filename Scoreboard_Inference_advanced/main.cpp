#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

int getMinProblemCount(int N, vector<int> S) {
  // Write your code here
  bool has_score_of_one = false;
  int contains_one_point_problem = 0;
  int contains_two_point_problem = 0;

  int largest_score = 0;
  int second_largest_score = 0;

  for (int score : S) {
      if (score % 3 == 1) {
          contains_one_point_problem = 1;
          if (score == 1) {
              has_score_of_one = true;
          }
      } else if (score % 3 == 2) {
          contains_two_point_problem = 1;
      }

      if (score > second_largest_score) {
          if (score > largest_score) {
              second_largest_score = largest_score;
              largest_score = score;
          } else if (score < largest_score) {
              second_largest_score = score;
          }
      }
  }

  int problem_count = (largest_score / 3) + contains_one_point_problem + contains_two_point_problem;

  // Remove an extraneous 3-point problem
  if (largest_score % 3 == 0 && contains_one_point_problem && contains_two_point_problem) {
      problem_count -= 1;
  }
  // Replace the 1-point problem with a 2-point problem and remove an extraneous 3-point problem
  else if (!has_score_of_one && contains_one_point_problem) {
      if (largest_score % 3 == 1 && second_largest_score != largest_score - 1) {
          problem_count -= 1;
      }
  }

  return problem_count;
}