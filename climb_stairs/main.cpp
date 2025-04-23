#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

int climbStairs(int n) {
    // Base case for 0th and 1st stair
    if (n == 0 || n == 1)
        return 1;

    // base case for 2nd stair
    if (n == 2)
        return 2;

    // Initializing a matrix of size n+1
    vector<int> dp(n + 1);

    // insert ans values for 0,1,2 stair
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    // building dp in bottom up manner
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}