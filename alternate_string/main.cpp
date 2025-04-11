#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

int alternate(string s) {
    unordered_map<char, int> freq;
    string alternate_string = "";
    
    for(auto a : s){
        freq[a]++;
    }
    vector<char> unique_char;
    vector<vector<char>> unique_combination;
    
    unordered_map<char,int>::iterator it;
    for(it = freq.begin(); it != freq.end(); it++){
        unique_char.push_back(it->first);
    }
    
    for(int i = 0; i < unique_char.size(); i++){
        for(int j = i+1; j < unique_char.size(); j++){
            unique_combination.push_back({unique_char[i], unique_char[j]});
        }
    }
    
    for(auto a : unique_combination){
        string temp = "";
        char last_char = '\0';
        bool completed = true;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == a[0] || s[i] == a[1]){
                if(last_char == s[i]){
                    completed = false;
                    break;
                }
                temp += s[i];
                last_char = s[i];
            }
        }
        if(completed && temp.length()>alternate_string.length()){
            alternate_string = temp;
        }
    }
    
    return alternate_string.size();
}