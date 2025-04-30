#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <set>
#include <random>
#include <stack>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    sort(strs.begin(), strs.end(), [](const auto &a, const auto &b){
        return a.length() < b.length();
    });

    string prefix = "";
    for(int i = 0; i < strs[0].length(); i++){
        bool notSame = false;
        for(int j = 0; j < strs.size(); j++){
            if(strs[j][i] != strs[0][i]){
                notSame = true;
                break;
            }
        }

        if(!notSame){
            prefix += string(1,strs[0][i]);
        }
        else{
            break;
        }
    }

    return prefix;
}