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
#include <queue>

using namespace std;

vector<int> shuffle(vector<int>& nums, int n) {
    vector<int> newArr(n*2);
    int j = 0;
    for(int i = 0; i < n; i++){
        newArr[j++] = nums[i];
        newArr[j++] = nums[i+n];
    }
    
    return newArr;
}