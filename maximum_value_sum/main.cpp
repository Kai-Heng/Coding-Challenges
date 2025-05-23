#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <queue>

using namespace std;

long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
    long long base = 0;
    long long sumPos = 0;
    long long minPos = LLONG_MAX;
    long long maxNeg = LLONG_MIN;
    int cntPos = 0;

    for (int v : nums) {
        base += v;
        long long d = (v ^ k) - (long long)v;
        if (d > 0) {
            ++cntPos;
            sumPos += d;
            minPos = min(minPos, d);
        } else if (d < 0) {
            maxNeg = max(maxNeg, d);
        }
    }

    long long bestDelta = 0;
    if (cntPos % 2 == 0) {
        bestDelta = sumPos;
    } else {
        long long option1 = (cntPos >= 1 ? sumPos - minPos : LLONG_MIN);
        long long option2 = (maxNeg != LLONG_MIN ? sumPos + maxNeg : LLONG_MIN);
        bestDelta = max(0LL, max(option1, option2));
    }

    return base + bestDelta;
}