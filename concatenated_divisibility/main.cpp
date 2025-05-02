#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <set>
#include <random>
#include <queue>

using namespace std;

long long modPow10(int len, int k){
    long long res = 1, base = 10 % k;
    while (len){
        if (len & 1) res = (res * base) % k;
        base = (base * base) % k;
        len >>= 1;
    }
    return res;
}
int digits(int x){ return to_string(x).size(); }

vector<int> concatenatedDivisibility(vector<int>& nums, int k) {
    int n = nums.size();
    if (n == 0) return {};

    /* pre-compute num_i mod k and 10^{len_i} mod k */
    vector<int> val(n), pow10(n);
    for (int i = 0; i < n; ++i){
        val[i]   = nums[i] % k;
        pow10[i] = (int)modPow10(digits(nums[i]), k);
    }

    /* --------  BFS on (mask, modulo)  -------- */
    const int FULL = (1 << n) - 1;
    vector<vector<char>> seen(1 << n, vector<char>(k, 0));
    struct State{ int mask, mod; };
    queue<State> q;

    /* parent[mask][mod] = {prevMask , prevMod , idxAdded } */
    struct Parent{ int pmask, pmod, idx; };
    vector<vector<Parent>> parent(1 << n, vector<Parent>(k, {-1,-1,-1}));

    seen[0][0] = 1;
    q.push({0,0});

    /* iterate candidate indices in lexicographic order:
       sort by value, then by original index  */
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    stable_sort(order.begin(), order.end(),
       [&](int a, int b){ return nums[a] < nums[b]; });

    while (!q.empty()){
        auto [mask, mod] = q.front(); q.pop();

        for (int idx : order) if (!(mask & (1<<idx))){
            int nmask = mask | (1<<idx);
            int nmod  = ( (long long)mod * pow10[idx] + val[idx] ) % k;
            if (seen[nmask][nmod]) continue;

            seen[nmask][nmod] = 1;
            parent[nmask][nmod] = {mask, mod, idx};
            if (nmask == FULL && nmod == 0){      // reached goal
                vector<int> answer;
                int cmask = nmask, cmod = nmod;
                while (cmask){
                    auto p = parent[cmask][cmod];
                    answer.push_back(nums[p.idx]);
                    cmask = p.pmask;
                    cmod  = p.pmod;
                }
                reverse(answer.begin(), answer.end());
                return answer;                     // lexicographically-smallest by BFS order
            }
            q.push({nmask, nmod});
        }
    }
    return {};   // no permutation works©leetcode
}