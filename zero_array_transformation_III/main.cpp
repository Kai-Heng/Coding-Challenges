#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <queue>

using namespace std;


struct Intv {int l, r;};

int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
    const int n = nums.size();
    const int q = queries.size();
    if (q == 0) return -1;                 // no intervals → impossible unless nums already 0
    if (*max_element(nums.begin(), nums.end()) == 0) return q; // all zero : can remove all

    /* sort intervals by left */
    vector<Intv> seg(q);
    for (int i = 0; i < q; ++i) seg[i] = {queries[i][0], queries[i][1]};
    sort(seg.begin(), seg.end(),
            [](const Intv& a, const Intv& b){ return a.l < b.l; });

    using MaxR = pair<int,int>;            // (right , index)  max‑heap
    priority_queue<MaxR> candidates;
    priority_queue<int, vector<int>, greater<int>> active; // right ends of kept intervals

    int ptr = 0;          // next interval to push into candidates
    int kept = 0;         // intervals we are forced to keep

    for (int i = 0; i < n; ++i) {
        /* push every interval whose left ≤ i */
        while (ptr < q && seg[ptr].l <= i)
            candidates.emplace(seg[ptr].r, ptr++);

        /* remove kept intervals that expired before i */
        while (!active.empty() && active.top() < i) active.pop();

        long need = nums[i] - (long)active.size();
        if (need <= 0) continue;           // already covered

        while (need-- > 0) {
            /* discard candidate intervals that do not reach i */
            while (!candidates.empty() && candidates.top().first < i)
                candidates.pop();

            if (candidates.empty()) return -1; // impossible

            auto [r, idx] = candidates.top(); candidates.pop();
            active.push(r);
            ++kept;
        }
    }
    return q - kept;      // maximum removable
}