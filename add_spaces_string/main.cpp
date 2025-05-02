#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <set>
#include <random>

using namespace std;

string addSpaces(string s, vector<int>& spaces) {
    string new_s = "";
    int i = 0;
    int j = 0;
    while(i < s.length()){
        if(j < spaces.size() && i == spaces[j]){
            new_s += " ";
            j++;
        }
        new_s += string(1,s[i]);
        
        i++;
    }

    return new_s;
}