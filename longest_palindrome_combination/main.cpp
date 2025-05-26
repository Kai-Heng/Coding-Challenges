#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <queue>

using namespace std;

int longestPalindrome(vector<string>& words) {
    unordered_map<string, int> words_s;
    bool hasPair = false;
    int count = 0;

    for(auto w : words){
        words_s[w]++;
    }

    for(auto &w : words_s){
        if(w.first[0] == w.first[1]){
            if(w.second % 2 == 1){
                count += (w.second - 1)*2;
                hasPair = true;
            }
            else{
                count += w.second * 2;
            }
        }
        else if(words_s.count(string(1,w.first[1]) + string(1, w.first[0]))){
            count += min(words_s[string(1,w.first[1]) + string(1, w.first[0])], words_s[w.first])*2;
            cout << w.first << endl;
        }
    }

    if(hasPair){
        count += 2;
    }

    return count;
}