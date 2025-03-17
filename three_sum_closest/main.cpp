#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    // 1. Sort the array
    sort(nums.begin(), nums.end());

    int n = nums.size();
    int closest_sum = nums[0] + nums[1] + nums[2]; // Start with any valid triple

    // 2. Outer loop over each 'i' from 0..(n-3)
    for(int i = 0; i < n-2; i++){
        int left = i + 1;
        int right = n - 1;

        // 3. Two-pointer search for each i
        while(left < right) {
            int current_sum = nums[i] + nums[left] + nums[right];

            // Update if this is closer to target
            if(abs(target - current_sum) < abs(target - closest_sum)){
                closest_sum = current_sum;
            }

            // Move pointers
            if(current_sum < target){
                ++left;   // try to get a bigger sum
            } else if(current_sum > target){
                --right;  // try to get a smaller sum
            } else {
                // current_sum == target -> can't get closer than exactly target
                return current_sum;
            }
        }
    }

    return closest_sum;
}