#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <deque>

using namespace std;

string caesarCipher(string s, int k) {
    string encrypted = "";
    deque<char> q;
    map<char, char> word_map;
    for(int i = 97; i <= 122; i++){
        q.push_back(i);
    }
    
    while(k--){
        q.push_back(q.front());
        q.pop_front();
    }
    
    int c_dec = 97;
    for(auto i : q){
        word_map[c_dec] = i;
        c_dec++;
    }
    
    for(int i = 0; i < s.length(); i++){
        if(word_map.count(tolower(s[i])) == 0){
            encrypted += s[i];
        }
        else{
            if(s[i] >= 65 && s[i] <= 90){
                encrypted += toupper(word_map[tolower(s[i])]);
            }
            else{
                encrypted += word_map[s[i]];
            }
            
        }
    }
    
    return encrypted;
}