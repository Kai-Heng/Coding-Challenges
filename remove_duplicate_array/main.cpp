#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    int prev = -101;
    int j = 0;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] != prev){
            nums[j] = nums[i];
            j++;
        }
        prev = nums[i];
    }

    return j;
}