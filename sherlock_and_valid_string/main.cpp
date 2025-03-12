/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

 string isValid(string s) {
    map<char, int> freq_char;
    for(int i = 0; i < s.length(); i++){
        if(freq_char.count(s[i]) == 0){
            freq_char.insert(pair<char, int>(s[i], 1));
        }
        else{
            freq_char.at(s[i])++;
        }
    }
    
    map<int,int> dominance;
    
    for(auto f : freq_char){
        if(dominance.count(f.second) == 0){
            dominance.insert(pair<int,int>(f.second, 1));
        }
        else{
            dominance.at(f.second)++;
        }
    }
    
    for(auto f : dominance){
        cout << f.first << " " << f.second << endl;
    }
    if(dominance.size() == 1) return "YES";
    
    if(dominance.size() > 2){
        return "NO";
    }
    else if(prev(dominance.end())->second >= dominance.begin()->second && dominance.begin()->second > 1){
        return "NO";
    }
    else if(prev(dominance.end())->second <= dominance.begin()->second && prev(dominance.end())->second > 1){
        return "NO";
    }
    else if(abs(prev(dominance.end())->first - dominance.begin()->first) > 1 && prev(dominance.end())->first > dominance.begin()->first && (dominance.begin()->second > prev(dominance.end())->second)){
        return "NO";
    }

    return "YES";
}