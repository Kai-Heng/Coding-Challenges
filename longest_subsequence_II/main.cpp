#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

int hamming(const string& a, const string& b) {
    int diff = 0;
    for (int i = 0; i < a.size(); ++i)
        diff += (a[i] != b[i]);
    return diff;
}

vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
    int n = words.size();
    vector<int> dp(n, 1), parent(n, -1);
    int maxLen = 1, endIdx = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (groups[i] != groups[j] &&
                words[i].length() == words[j].length() &&
                hamming(words[i], words[j]) == 1) {
                
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
        }
        if (dp[i] > maxLen) {
            maxLen = dp[i];
            endIdx = i;
        }
    }

    // Reconstruct path
    vector<string> res;
    while (endIdx != -1) {
        res.push_back(words[endIdx]);
        endIdx = parent[endIdx];
    }
    reverse(res.begin(), res.end());
    return res;
}