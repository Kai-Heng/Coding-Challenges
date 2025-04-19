#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <set>

using namespace std;

bool checkInclusion(string s1, string s2) {
    if(s1.length() > s2.length()) return false;
    unordered_map<char, int> s1_freq;
    
    for(auto s : s1){
        s1_freq[s]++;
    }
    
    unordered_map<char, int> s2_freq;
    for(int j = 0; j < s1.length(); j++){
        s2_freq[s2[j]]++;
    }
    
    if(s1_freq.size() == s2_freq.size()){
        int no_break = true;
        for(auto f : s1_freq){
            if(s2_freq.count(f.first) == 0){
                no_break = false;
                break;
            }
            else if(s2_freq[f.first] != f.second){
                no_break = false;
                break;
            }
        }
        if(no_break)
            return true;
    }
    
    
    for(int i = 1; i < s2.length()-s1.length()+1; i++){
        s2_freq[s2[i-1]]--;
        
        
        if(s2_freq[s2[i-1]] == 0){
            s2_freq.erase(s2[i-1]);
        }
        
        s2_freq[s2[s1.length()+i-1]]++;
        
        
        if(s1_freq.size() == s2_freq.size()){
            int no_break = true;
            for(auto f : s1_freq){
                if(s2_freq.count(f.first) == 0){
                    no_break = false;
                    break;
                }
                else if(s2_freq[f.first] != f.second){
                    no_break = false;
                    break;
                }
            }
            if(no_break)
                return true;
        }
    }
    
    return false;
}