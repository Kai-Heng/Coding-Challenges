#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

int shortPalindrome(string s) {
    long long numOfWays = 0;
    const int MOD = 1e9 + 7;
    
    vector<int> unique_letter(26, 0);
    vector<vector<int>> unique_pair(26, vector<int>(26, 0));
    vector<vector<int>> unique_triplet(26, vector<int>(26, 0));
    
    for(int i = s.length()-1; i >= 0; i--){
        int c = s[i] - 'a';
        
        for(int j = 0; j < 26; j++){
            numOfWays = (numOfWays+unique_triplet[c][j]) % MOD;
        }
        
        for(int j = 0; j < 26; j++){
            unique_triplet[j][c] = (unique_triplet[j][c] + unique_pair[j][c]) % MOD;
        }
        
        for(int j = 0; j < 26; j++){
            unique_pair[j][c] = (unique_pair[j][c] + unique_letter[j]) % MOD;
        }
        
        unique_letter[c]++;
    }
    // for(int i = 0; i < s.length(); i++){
    //     for(int j = i +1; j < s.length(); j++){
    //         for(int k = j + 1; k < s.length(); k++){
    //             for(int m = k + 1; m < s.length(); m++){
    //                 if(s[m] == s[i] && s[k] == s[j]){
    //                     numOfWays++;
    //                 }
    //             }
    //         }
    //     }
    // }
    
    
    
    return numOfWays;
}