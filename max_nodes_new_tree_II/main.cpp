#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
    int n = edges1.size() + 1;
    int m = edges2.size() + 1;

    // --- build adjacency lists
    vector<vector<int>> g1(n), g2(m);
    for (auto &e : edges1) { g1[e[0]].push_back(e[1]); g1[e[1]].push_back(e[0]); }
    for (auto &e : edges2) { g2[e[0]].push_back(e[1]); g2[e[1]].push_back(e[0]); }

    // --- compute depth parity (0 = even, 1 = odd)
    auto getParity = [](const vector<vector<int>>& g, int root) {
        vector<int> depth(g.size(), -1);
        stack<int> st; st.push(root); depth[root] = 0;
        while (!st.empty()) {
            int u = st.top(); st.pop();
            for (int v : g[u])
                if (depth[v] == -1) {
                    depth[v] = depth[u] ^ 1;
                    st.push(v);
                }
        }
        return depth;
    };

    vector<int> dep1 = getParity(g1, 0);
    vector<int> dep2 = getParity(g2, 0);

    // --- parity counts
    int even1 = 0, odd1 = 0, even2 = 0, odd2 = 0;
    for (int d : dep1) (d ? odd1 : even1)++;
    for (int d : dep2) (d ? odd2 : even2)++;

    int bestTree2 = max(even2, odd2);               // what we can always realise
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        int sameParityInT1 = (dep1[i] ? odd1 : even1);
        ans[i] = sameParityInT1 + bestTree2;
    }
    return ans;
}