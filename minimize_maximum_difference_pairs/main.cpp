#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <unordered_map>
#include <numeric>
#include <algorithm>
#include <math.h>

using namespace std;

// greedy test described above
static bool feasible(const vector<int>& a, int p, int D) {
    int cnt = 0;
    for (int i = 0; i + 1 < (int)a.size(); ) {
        if (a[i + 1] - a[i] <= D) { ++cnt; i += 2; }
        else                        ++i;
        if (cnt >= p) return true;          // early exit
    }
    return false;
}

int minimizeMax(vector<int>& nums, int p) {
    sort(nums.begin(), nums.end());

    int lo = 0, hi = nums.back() - nums.front();
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (feasible(nums, p, mid))
            hi = mid;           // try smaller maximum
        else
            lo = mid + 1;       // need larger allowance
    }
    return lo;                  // minimal possible maximum difference
}