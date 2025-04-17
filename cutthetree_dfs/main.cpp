#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <deque>
#include <unordered_set>
#include <cmath>
#include <numeric>

using namespace std;

int cutTheTree(vector<int> data, vector<vector<int>> edges) {
    int n = data.size();
    vector<vector<int>> tree(n);
    for (auto &e : edges) {
        int u = e[0] - 1;
        int v = e[1] - 1;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<int> subtreeSum(n, 0);
    vector<bool> visited(n, false);
    int totalSum = accumulate(data.begin(), data.end(), 0);
    int minDiff = INT_MAX;

    function<int(int)> dfs = [&](int node) {
        visited[node] = true;
        int sum = data[node];
        for (int nei : tree[node]) {
            if (!visited[nei]) {
                sum += dfs(nei);
            }
        }
        subtreeSum[node] = sum;
        if (node != 0) {  // don't cut the whole tree at root
            minDiff = min(minDiff, abs(totalSum - 2 * sum));
        }
        return sum;
    };

    dfs(0);
    return minDiff;
}