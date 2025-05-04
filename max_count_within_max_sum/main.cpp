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

int maxCount(vector<int>& banned, int n, int maxSum) {
    stack<int> num;
    unordered_set<int> ban(banned.begin(), banned.end());
    int sum = 0;
    for(int i = 1; i <=n; i++){
        if(ban.count(i) == 0){
            sum += i;
            num.push(i);
        }
    }

    if(sum <= maxSum) return num.size();

    while(sum > maxSum){
        sum -= num.top();
        num.pop();
    }

    return num.size();
}