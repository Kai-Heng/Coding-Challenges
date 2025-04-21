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

int pivotIndex(vector<int>& nums) {
    int total = accumulate(nums.begin(), nums.end(), 0);
    int left_sum = 0;

    for (int i = 0; i < nums.size(); i++) {
        int right_sum = total - left_sum - nums[i];
        if (left_sum == right_sum) return i;
        left_sum += nums[i];
    }

    return -1;
}