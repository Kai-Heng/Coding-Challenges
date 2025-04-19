#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <set>

using namespace std;

bool wordsCompare(string a, string b, unordered_map<char, int> dict){
    int a_i = 0;
    int b_i = 0;
    
    while(a_i < a.length() && b_i < b.length()){
        if(a[a_i] != b[b_i]){
            if(dict[a[a_i]] > dict[b[b_i]]){
                return false;
            }
            else if(dict[a[a_i]] < dict[b[b_i]]){
                return true;
            }
        }
        a_i++;
        b_i++;
    }
    
    if(a_i < a.length()){
        if(b[b_i-1] == a[a_i-1]){
            return false;
        }
    }
    
    
    return true;
}
bool isAlienSorted(vector<string>& words, string order) {
    // 1. If word[0] > word[1], if the first kth character were same, and if k+1 larger than in word[0] > word[1] according to 'order' return false;
    // 2. If word[0].length() > word[1].length(), result false. word[0]: abc, word[1]: ad this should return true. 
    
    // Use for-loop to compare two word, 'order' matter
    unordered_map<char, int> char_order;
    
    for(int i = 0; i < order.length(); i++){
        char_order[order[i]] = i + 1;
    }
    
    for(int i = 0; i < words.size()-1; i++){
        if(!wordsCompare(words[i], words[i+1], char_order)){
            return false;
        }
    }
    
    return true;
    
}