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

vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
    unordered_set<int> key_idx;

    int left = 0;
    int right = nums.size()-1;
    while(left <= right){
        if(left == right && nums[left] == key){
            key_idx.insert(left);
            break;
        }

        if(nums[left] == key){
            key_idx.insert(left);
        }

        if(nums[right] == key){
            key_idx.insert(right);
        }

        left++;
        right--;
    }

    int counter = 0;
    vector<int> ans;

    for(int i = 0; i < nums.size(); i++){
        for(auto j : key_idx){
            if(abs(i-j) <= k){
                ans.push_back(counter);
                break;
            }
        }
        counter++;
    }

    return ans;
}