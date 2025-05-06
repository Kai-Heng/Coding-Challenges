#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <set>
#include <random>
#include <stack>
#include <unordered_set>

using namespace std;

vector<int> buildArray(vector<int>& nums) {
    vector<int> newArr(nums.size());

    for(int i = 0; i < nums.size(); i++){
        newArr[i] = nums[nums[i]];
    }

    return newArr;
}