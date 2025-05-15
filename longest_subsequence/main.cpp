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


vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
    vector<string> res;

    int prev = groups[0];
    res.push_back(words[0]);

    for(int i = 1; i < groups.size(); i++){
        if(groups[i] != prev){
            prev = !prev;
            res.push_back(words[i]);
        }
    }

    return res;
}