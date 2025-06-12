#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <unordered_map>
#include <numeric>
#include <algorithm>
#include <math.h>

using namespace std;

bool dfs(string s, string dict, int i, int d_i){
    if(d_i >= dict.size()) return true;
    
    if(i > s.length()) return false;
    
    if(s[i] == dict[d_i]){
        d_i++;
    }
    
    return dfs(s, dict, i+1, d_i);
}
string getValidWord(string s, vector<string> dictionary) {
    string word = "{";
    for(int i = 0; i < dictionary.size(); i++){
        if(dfs(s, dictionary[i], 0, 0)){
            word = min(word, dictionary[i]);
            // found.push_back(dictionary[i]);
        }
    }
    // sort(found.begin(), found.end());
    return word == "{" ? "-1" : word;
}