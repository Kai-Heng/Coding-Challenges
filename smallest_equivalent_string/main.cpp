#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <queue>
#include <stack>
#include <math.h>
#include <numeric>
#include <set>

using namespace std;

string smallestEquivalentString(string s1, string s2, string baseStr) {
    unordered_map<char, int> dict;
    vector<set<char>> group;
    string ans = "";

    for(int i = 0; i < s1.size(); i++){
        if(s1[i] == s2[i]){
            if(dict.count(s1[i]) == 0){
                group.push_back({s1[i]});
                dict[s1[i]] = group.size()-1;
            }
        }
        else{
            if(dict.count(s1[i]) == 0 && dict.count(s2[i])){
                group[dict[s2[i]]].insert(s1[i]);
                dict[s1[i]] = dict[s2[i]];
            }
            else if(dict.count(s1[i]) && dict.count(s2[i]) == 0){
                group[dict[s1[i]]].insert(s2[i]);
                dict[s2[i]] = dict[s1[i]];
            }
            else if(dict.count(s1[i]) == 0 && dict.count(s2[i]) == 0){
                group.push_back({s1[i], s2[i]});
                dict[s2[i]] = group.size()-1;
                dict[s1[i]] = group.size()-1;
            }
            else{
                if(dict[s2[i]] != dict[s1[i]]){
                    for(auto s : group[dict[s2[i]]]){
                        group[dict[s1[i]]].insert(s);
                        dict[s] = dict[s1[i]];
                    }
                }
            }
        }
    }

    for(int i = 0; i < baseStr.length(); i++){
        if(dict.count(baseStr[i]) == 0){
            ans += baseStr[i];
        }
        else{
            ans += *group[dict[baseStr[i]]].begin();
        }
        
    }

    return ans;
}