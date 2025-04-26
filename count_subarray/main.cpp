#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <unordered_set>
#include <sstream>
#include <queue>

using namespace std;

long long countSubarrays(vector<int>& nums, int minK, int maxK) {
    long long result = 0;
    int lastMin = -1, lastMax = -1, lastInvalid = -1;
    int n = nums.size();

    for (int i = 0; i < n; ++i) {
        if (nums[i] < minK || nums[i] > maxK) {
            lastInvalid = i;
        }
        if (nums[i] == minK) {
            lastMin = i;
        }
        if (nums[i] == maxK) {
            lastMax = i;
        }

        int validStart = min(lastMin, lastMax);
        if (validStart > lastInvalid) {
            result += validStart - lastInvalid;
        }
    }

    return result;
}