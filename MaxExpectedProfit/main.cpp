#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

double getMaxExpectedProfit(int N, vector<int> V, int C, double S) {
    // Write your code here
  /**
    * getMaxExpectedProfit:
    *   N  = number of days
    *   V  = array of package values (size N)
    *   C  = cost to enter and collect on any chosen day
    *   S  = probability that the mail room is robbed each night
    *
    * Returns the maximum expected net profit.
  */
                              
  // dp[i] = maximum expected profit from day i..(N-1), assuming mail room is empty at start of day i
  vector<double> dp(N+1, 0.0);

  // Compute dp[] in reverse order: from N-1 down to 0
  // Base case: dp[N] = 0 (after the last day, there's nothing more to collect)
  dp[N] = 0.0;
  
  // Fill dp[] in reverse (from day N-1 down to 0)
  for (int i = N - 1; i >= 0; i--) {
    // Option 1: don't collect any more packages => profit = 0
    double best = 0.0;

    // Option 2: choose day j >= i to collect
    // Calculate the expected sum of packages that survive until morning of j
    // Then pay cost C, plus dp[j+1].
    double expectedSum = 0.0;

    for (int j = i; j < N; j++) {
      // Update expected sum for collecting from i..j
      if (j == i) {
          // First package
          expectedSum = (double)V[i];
      } else {
          // Extend from previous j-1 to j
          expectedSum = (1.0 - S) * expectedSum + (double)V[j];
      }

      // If collect on day j, we pay cost C once, then add dp[j+1]
      double candidate = expectedSum - C + ( (j+1 <= N) ? dp[j+1] : 0.0 );
      best = max(best, candidate);
    }

    // dp[i] is the maximum of "skip collecting" vs. "collect on some j"
    dp[i] = max(0.0, best);
  }

  // dp[0] is the best expected profit starting from day 0
  return dp[0];
}