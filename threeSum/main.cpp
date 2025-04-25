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

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    
    for(int i = 0; i < nums.size()-2; i++){
        if (i > 0 && nums[i] == nums[i - 1]) continue; // skip duplicate i

        int left = i+1;
        int right = nums.size()-1;
        
        while(left < right){
            int sum = nums[i]+nums[left]+nums[right];
            
            if(sum < 0){
                ++left;   // try to get a bigger sum
            } else if(sum > 0){
                --right;  // try to get a smaller sum
            } else {
                // current_sum == target -> can't get closer than exactly target
                result.push_back({nums[i], nums[left], nums[right]});
                // skip duplicates for left and right
                while (left < right && nums[left] == nums[left + 1]) ++left;
                while (left < right && nums[right] == nums[right - 1]) --right;
                ++left;
                --right;
            }
        }
    }
    
    return result;
}