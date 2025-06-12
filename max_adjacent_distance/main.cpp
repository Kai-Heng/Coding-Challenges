#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int maxAdjacentDistance(vector<int>& nums) {
    int max_diff = abs(nums[0]-nums[nums.size()-1]);

    int k = nums.size()-1;
    for(int i = 0; i < nums.size()-1; i++){
        max_diff = max(max_diff, abs(nums[i]-nums[i+1]));
        max_diff = max(max_diff, abs(nums[k]-nums[k-1]));
    }

    return max_diff;
}
