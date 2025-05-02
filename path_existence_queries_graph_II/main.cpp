#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <set>
#include <random>

using namespace std;

static constexpr int LOG = 17;
vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
    /* 1. sort indices by value */
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(),
         [&](int a, int b){ return nums[a] < nums[b]; });

    vector<int> pos(n);                       // original id → sorted position
    for (int i = 0; i < n; ++i) pos[ord[i]] = i;

    /* 2. last[i] : rightmost one-step reach */
    vector<int> last(n);
    int r = 0;
    for (int l = 0; l < n; ++l) {
        while (r + 1 < n && nums[ord[r + 1]] - nums[ord[l]] <= maxDiff)
            ++r;
        last[l] = r;
        if (l == r) ++r;                      // keep window valid
    }

    /* 3. doubling table up[k][i] */
    vector<array<int, LOG + 1>> up(n);
    for (int i = 0; i < n; ++i) up[i][0] = last[i];
    for (int k = 1; k <= LOG; ++k)
        for (int i = 0; i < n; ++i)
            up[i][k] = up[ up[i][k - 1] ][k - 1];

    /* 4. answer queries */
    vector<int> ans;
    ans.reserve(queries.size());

    for (auto& qv : queries) {
        int u = qv[0], v = qv[1];
        int p = pos[u], q = pos[v];
        if (p == q) { ans.push_back(0); continue; }
        if (p  > q) swap(p, q);               // search left → right

        int cur = p, steps = 0;
        for (int k = LOG; k >= 0; --k) {
            int nxt = up[cur][k];
            if (nxt < q) {                    // still cannot reach q
                cur   = nxt;
                steps += 1 << k;
            }
        }
        if (last[cur] < q) ans.push_back(-1); // cannot reach
        else                ans.push_back(steps + 1);
    }
    return ans;
}