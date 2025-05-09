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
#include <unordered_set>
#include <queue>

using namespace std;

int dieSimulator(int n, vector<int>& rollMax) {
    const int MOD = 1e9 + 7;
                
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(6, vector<int>(16, 0)));
    for (int j = 0; j < 6; ++j) {
        dp[1][j][1] = 1;
    }
    
    // Build up dp
    for (int i = 1; i < n; ++i) {             // i rolls so far
        for (int last = 0; last < 6; ++last) { // last number rolled
            for (int count = 1; count <= rollMax[last]; ++count) { // how many times consecutively
                if (dp[i][last][count] == 0) continue;

                for (int next = 0; next < 6; ++next) { // try next number
                    if (next == last) {
                        if (count + 1 <= rollMax[next]) {
                            dp[i+1][next][count+1] = (dp[i+1][next][count+1] + dp[i][last][count]) % MOD;
                        }
                    } else {
                        dp[i+1][next][1] = (dp[i+1][next][1] + dp[i][last][count]) % MOD;
                    }
                }
            }
        }
    }

    // Sum all possibilities at exactly n rolls
    int ans = 0;
    for (int j = 0; j < 6; ++j) {
        for (int k = 1; k <= rollMax[j]; ++k) {
            ans = (ans + dp[n][j][k]) % MOD;
        }
    }
    return ans;
    
}