#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <unordered_map>
#include <numeric>
#include <algorithm>
#include <math.h>

using namespace std;

vector<vector<int>> divideArray(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    int i = 0;
    while(i+2 < nums.size()){
        int a = nums[i];
        int b = nums[i+1];
        int c = nums[i+2];

        if(abs(a-b) <= k && abs(b-c) <= k && abs(a-c) <= k){
            ans.push_back({a,b,c});
        }
        i+=3;
    }

    return (ans.size() == nums.size()/3) ? ans : vector<vector<int>>{};
}