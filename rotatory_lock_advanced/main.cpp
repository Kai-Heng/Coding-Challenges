#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

int minDist(int a, int b, int N) {
    return min(abs(a - b), N - abs(a - b));
}

long long getMinCodeEntryTime(int N, int M, vector<int> C) {
  // Write your code here
  unordered_map<int, long long> dp_prev, dp_curr;

  int first_digit = C[0];
  dp_prev[1] = minDist(1, first_digit, N); // wheel1 at 1, wheel2 selects C[0]

  for (int i = 1; i < M; ++i) {
      int curr = C[i];
      int prev = C[i - 1];
      dp_curr.clear();

      for (auto &[other_wheel_pos, time] : dp_prev) {
          // Option 1: move the wheel at prev to curr (other wheel remains at same position)
          long long t1 = time + minDist(prev, curr, N);
          if (!dp_curr.count(other_wheel_pos) || t1 < dp_curr[other_wheel_pos])
              dp_curr[other_wheel_pos] = t1;

          // Option 2: move the wheel at other_wheel_pos to curr (prev becomes the "other" now)
          long long t2 = time + minDist(other_wheel_pos, curr, N);
          if (!dp_curr.count(prev) || t2 < dp_curr[prev])
              dp_curr[prev] = t2;
      }

      dp_prev = dp_curr; // move to next step
  }

  // Return min of final times
  long long min_time = LLONG_MAX;
  for (auto &[_, time] : dp_prev)
      min_time = min(min_time, time);

  return min_time;
}