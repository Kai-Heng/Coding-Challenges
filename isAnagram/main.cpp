#include <stdlib.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
    public:
        bool isAnagram(string s, string t) {
            if(s.length() != t.length()) return false;
            
            unordered_map<char, int> s_f;
            unordered_map<char, int> t_f;
            for(int i = 0; i < s.length(); i++){
                s_f[s[i]]++;
                t_f[t[i]]++;
            }
            
            for(auto f : s_f){
                if(t_f.count(f.first) == 0) return false;
                else if(t_f[f.first] != f.second) return false;
            }
            
            return true;
        }
    };