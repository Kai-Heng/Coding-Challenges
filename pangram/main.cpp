#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <deque>

using namespace std;

string pangrams(string s) {
    vector<int> visited(26, false);
    
    for(int i = 0; i < s.length(); i++){
        visited[tolower(s[i])-'a'] = true;
    }
    
    for(auto v : visited){
        if(!v){
            return "not pangram";
        }
    }
    
    return "pangram";
}