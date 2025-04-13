#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <deque>
#include <unordered_set>

using namespace std;

vector<string> weightedUniformStrings(string s, vector<long long> queries) {
    vector<string> result;
    unordered_set<long long> substring;
    char prev = 0;
    long long current_weight = 0;
    for(long long i = 0; i < s.size(); i++){
        if(prev == 0 || prev != s[i]){
            prev = s[i];
            current_weight = prev - 'a' + 1;
        }
        else{
            prev = s[i];
            current_weight += s[i] - 'a' + 1;
        }
        substring.insert(current_weight);
    }
    
    for(auto q : queries){
        if(substring.count(q) != 0){
            result.push_back("Yes");
        }
        else{
            result.push_back("No");
        }
    }
    
    return result;
}