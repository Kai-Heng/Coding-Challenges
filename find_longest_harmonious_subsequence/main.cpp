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

int findLHS(vector<int>& nums) {
    unordered_map<int,int> f;

    for(auto i : nums){
        f[i]++;
    }

    vector<pair<int,int>> f_arr(f.begin(), f.end());
    sort(f_arr.begin(), f_arr.end(), [](const auto &a, const auto &b){
        return a.first < b.first;
    });
    
    int max_len = 0;
    for(int i = 0; i+1 < f_arr.size(); i++){
        if(f_arr[i+1].first - f_arr[i].first == 1){
            max_len = max(max_len, f_arr[i+1].second + f_arr[i].second);
        }
    }

    return max_len;
}