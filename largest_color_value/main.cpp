#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <queue>

using namespace std;

int largestPathValue(string colors, vector<vector<int>>& edges) {
    int n = colors.size();
    vector<vector<int>> adj(n);
    vector<int> indeg(n, 0);
    for (auto& e : edges) {
        adj[e[0]].push_back(e[1]);
        ++indeg[e[1]];
    }

    queue<int> q;
    for (int i = 0; i < n; ++i)
        if (indeg[i] == 0) q.push(i);

    vector<array<int, 26>> dp(n);
    for (int i = 0; i < n; ++i)
        dp[i].fill(0);

    int seen = 0, ans = 0;

    while (!q.empty()) {
        int v = q.front(); q.pop();
        ++seen;

        int c = colors[v] - 'a';
        dp[v][c] += 1;                // include own color
        ans = max(ans, dp[v][c]);

        for (int nei : adj[v]) {
            for (int k = 0; k < 26; ++k)
                dp[nei][k] = max(dp[nei][k], dp[v][k]);

            if (--indeg[nei] == 0)
                q.push(nei);
        }
    }
    return (seen == n) ? ans : -1;    // cycle check
}