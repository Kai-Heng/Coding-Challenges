#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <unordered_set>
#include <sstream>

using namespace std;

bool wordPattern(string pattern, string s) {
    unordered_map<char, string> unique;
    unordered_set<string> found;
    stringstream ss(s);
    string word;
    vector<string> words;
    
    while(ss >> word){
        words.push_back(word);
    }
    
    if(pattern.length() != words.size()) return false;
    for(int i = 0; i < pattern.size(); i++){
        if(unique.count(pattern[i]) == 0){
            if(found.count(words[i])) return false;
            unique[pattern[i]] = words[i];
            found.insert(words[i]);
        }
        else{
            if(unique[pattern[i]] != words[i]){
                return false;
            }
            
        }
    }
    
    return true;
    
}