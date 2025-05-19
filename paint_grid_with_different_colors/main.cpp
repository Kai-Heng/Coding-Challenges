#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

void dfs(int m, vector<int>& path, vector<vector<int>>& states) {
    if (path.size() == m) {
        states.push_back(path);
        return;
    }
    for (int color = 0; color < 3; ++color) {
        if (path.empty() || path.back() != color) {
            path.push_back(color);
            dfs(m, path, states);
            path.pop_back();
        }
    }
}

bool isCompatible(const vector<int>& a, const vector<int>& b) {
    for (int i = 0; i < a.size(); ++i)
        if (a[i] == b[i])
            return false;
    return true;
}

int colorTheGrid(int m, int n) {
    vector<vector<int>> states;
    vector<int> path;
    dfs(m, path, states); // all valid column states

    int sz = states.size();
    vector<vector<int>> dp(n, vector<int>(sz, 0));

    // Initialize first column
    for (int i = 0; i < sz; ++i)
        dp[0][i] = 1;

    // Transition across columns
    for (int col = 1; col < n; ++col) {
        for (int curr = 0; curr < sz; ++curr) {
            for (int prev = 0; prev < sz; ++prev) {
                if (isCompatible(states[curr], states[prev])) {
                    dp[col][curr] = (dp[col][curr] + dp[col - 1][prev]) % MOD;
                }
            }
        }
    }

    // Sum all ways at the last column
    int total = 0;
    for (int i = 0; i < sz; ++i)
        total = (total + dp[n - 1][i]) % MOD;
    return total;
}