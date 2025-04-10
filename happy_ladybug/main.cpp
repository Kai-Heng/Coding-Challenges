#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

string happyLadybugs(string b) {
    unordered_map<char, int> freq;
    bool haveUnderscores = false;
    
    for(auto c : b){
        freq[c]++;
        if(c == '_'){
            haveUnderscores = true;
        }
    }
    
    if(!haveUnderscores){
        for(int i = 0; i < b.length()-1; i++){
            if(b[i] == b[i+1] || (i != 0 && b[i] == b[i-1])){
                continue;
            }
            return "NO";
        }
    }
    
    for(auto f : freq){
        if(f.first != '_' && f.second < 2){
            return "NO";
        }
    }
    
    return "YES";
}