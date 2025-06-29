#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <unordered_map>
#include <numeric>
#include <algorithm>
#include <math.h>
#include <unordered_set>

using namespace std;

vector<int> maxSubsequence(vector<int>& nums, int k) {
    vector<int> temp(nums.begin(), nums.end());

    sort(nums.begin(), nums.end());

    unordered_map<int, int> f;
    vector<int> ans;

    int i = nums.size()-k;
    while(i < nums.size()){
        f[nums[i++]]++;
    }

    for(int j = 0; j < temp.size(); j++){
        if(f.count(temp[j]) && f[temp[j]] > 0){
            ans.push_back(temp[j]);
            f[temp[j]]--;
            k--;
        }
        if(k == 0) break;
    }

    return ans;
}