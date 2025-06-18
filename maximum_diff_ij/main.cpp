#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <unordered_map>
#include <numeric>
#include <algorithm>
#include <math.h>

using namespace std;

int maximumDifference(vector<int>& nums) {
    int max_diff = -1;

    int premin = nums[0];
    for(int i = 1; i < nums.size(); i++){
        if(nums[i] > premin){
            max_diff = max(max_diff, nums[i] - premin);
        }
        else{
            premin = nums[i];
        }
    }
    return max_diff;
}