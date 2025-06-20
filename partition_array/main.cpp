#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <unordered_map>
#include <numeric>
#include <algorithm>
#include <math.h>

using namespace std;

int partitionArray(vector<int>& nums, int k) {
    int partition = 0;

    sort(nums.begin(), nums.end());
    int i = 0;
    while(i < nums.size()){
        int j = i+1;
        while(j < nums.size() && nums[j] - nums[i] <= k){
            j++;
        }
        partition++;
        i = j;
    }

    return partition;
}