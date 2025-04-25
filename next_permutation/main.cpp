#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <unordered_set>
#include <stack>

using namespace std;

void nextPermutation(vector<int>& nums) {
    int i = nums.size() - 2;

    // Step 1: Find first decreasing element from the back
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        --i;
    }

    // Step 2: If found, find the element just larger than nums[i]
    if (i >= 0) {
        int j = nums.size() - 1;
        while (nums[j] <= nums[i]) {
            --j;
        }
        swap(nums[i], nums[j]);
    }

    // Step 3: Reverse the remaining elements after i
    reverse(nums.begin() + i + 1, nums.end());
}