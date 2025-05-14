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

using p = pair<int,int>;
struct Compare{
    bool operator()(p a, p b) {
        return a.second == b.second ? a.first > b.first : a.second > b.second; // min-heap
    }
};

// O(K*N)
vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
    while(k--){
        int min = nums[0];
        int id = 0;
        for(int i = 1; i < nums.size(); i++){
            if(min > nums[i]){
                min = nums[i];
                id = i;
            }
        }
        nums[id] *= multiplier;
    }
    return nums;
}

// Min-heap O(n + k log n)
vector<int> getFinalState1(vector<int>& nums, int k, int multiplier) {
    priority_queue<p, vector<p>, Compare> q;

    for(int i = 0; i < nums.size(); i++){
        q.push({i, nums[i]});
    }

    while(k--){
        p temp = q.top();
        temp.second *= multiplier;
        q.pop();
        q.push(temp);
        nums[temp.first] = temp.second;
    }
    return nums;
}