#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

string superReducedString(string s) {
    string reducedString = "";
    vector<char> s_arr(s.begin(), s.end());

    int i = 0;
    int j = i+1;
    while(j < s_arr.size()){
        if(s_arr[i] == s_arr[j]){
            s_arr.erase(s_arr.begin()+j);
            s_arr.erase(s_arr.begin()+i);
            i = 0;
            j = i + 1;
        }
        else{
            i++;
            j++;
        }
    }
    
    for(auto c : s_arr){
        reducedString += c;
    }
    
    return reducedString.empty() ? "Empty String" : reducedString;
}