#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <set>
#include <random>
#include <stack>

using namespace std;


bool isMatch(string s, string p) {
    int m = s.size(), n = p.size();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    
    dp[0][0] = true; // empty string matches empty pattern
    
    // Deal with patterns like a*, a*b*, a*b*c* that can match empty string
    for (int j = 2; j <= n; j += 2) {
        if (p[j-1] == '*' && dp[0][j-2]) {
            dp[0][j] = true;
        }
    }
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (p[j-1] == '*') {
                // Two cases:
                // 1. Treat '*' as matching zero occurrence
                dp[i][j] = dp[i][j-2];
                
                // 2. Treat '*' as matching one or more occurrences
                if (p[j-2] == '.' || p[j-2] == s[i-1]) {
                    dp[i][j] = dp[i][j] || dp[i-1][j];
                }
            } else if (p[j-1] == '.' || p[j-1] == s[i-1]) {
                // Match current character
                dp[i][j] = dp[i-1][j-1];
            }
        }
    }
    
    return dp[m][n];
}