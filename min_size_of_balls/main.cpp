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

using namespace std;

int minimumSize(vector<int>& nums, int maxOperations) {
    int lo = 1;                          // penalty can't be smaller than 1
    int hi = *max_element(nums.begin(), nums.end());

    auto enough = [&](int P) -> bool {
        long long opsNeeded = 0;
        for (int x : nums) {
            // ceil(x / P) - 1   <=>   (x - 1) / P
            opsNeeded += (x - 1) / P;
            if (opsNeeded > maxOperations) return false; // early exit
        }
        return opsNeeded <= maxOperations;
    };

    while (lo < hi) {
        int mid = (lo + hi) >> 1;        // candidate penalty
        if (enough(mid))
            hi = mid;                    // can achieve ≤ mid, try smaller
        else
            lo = mid + 1;                // need larger penalty
    }
    return lo;                           // minimal feasible penalty
}