#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

bool canConstruct(string s, int k) {
    unordered_map<char, int> freq;
    for(int i = 0; i < s.length(); i++){
        freq[s[i]]++;
    }
    
    int count = 0;
    for(auto f : freq){
        if(f.second % 2 != 0){
            count++;
        }
    }
    if (k > s.length()) return false;
    
    return count <= k;
}