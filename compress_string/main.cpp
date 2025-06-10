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
#include <unordered_set>
#include <queue>

using namespace std;

int compress(vector<char>& chars) {
    // 1. If the group is length of 1, append it to s
    // 2. Use tracker to track if there is a consecutive same character
    // 3. if the prev character not equal to curr character, append the group size with the prev character.
    // aaabbbccc
    // Expecting: a3b3c3
    // Case sensitive
    // * uses only constant extra space

    int tracker = 1;
    char prev_char = chars[0];
    vector<char> compressed;

    for(int i = 1; i < chars.size(); i++){
        if(chars[i] != prev_char){
            compressed.push_back(prev_char);
            if(tracker > 1){
                string temp = to_string(tracker);

                for(int j = 0; j < temp.size(); j++){
                    compressed.push_back(temp[j]);
                }
            }
            
            prev_char = chars[i];
            tracker = 1;
        }
        else{
            tracker++;
        }
    }

    compressed.push_back(prev_char);

    if(tracker > 1){
        string temp = to_string(tracker);

        for(int j = 0; j < temp.size(); j++){
            compressed.push_back(temp[j]);
        }
    }

    chars.clear();
    chars.resize(compressed.size());
    for(int i = 0; i < chars.size(); i++){
        chars[i] = compressed[i];
    }

    return compressed.size();
}