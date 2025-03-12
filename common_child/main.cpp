#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

/**
 * SHINCHAN
 * NOHARAAA
 * 
 * longest string is NHA, length is 3
 * dp[n][n] is the longest common string
 * 
 *  0 0 0 0 0 0 0 0 0 
    0 0 0 0 0 0 0 0 0 
    0 0 0 1 1 1 1 1 1 
    0 0 0 1 1 1 1 1 1 
    0 1 1 1 1 1 1 1 1 
    0 1 1 1 1 1 1 1 1 
    0 1 1 2 2 2 2 2 2 
    0 1 1 2 3 3 3 3 3 
    0 1 1 2 3 3 3 3 3 
 */
int commonChild(string s1, string s2) {
    int n = s1.length();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    // Fill DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][n]; // Length of the longest common subsequence
}