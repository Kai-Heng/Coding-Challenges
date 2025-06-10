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

int maxDifference(string s) {
    // Problem: find the max different between odd freq and even frequency
    // 1. use unordered_map to track the character's freq
    // 2. find the max freq for even and min freq for even
    //  find the max freq for odd and max freq for odd
    // 3. find max_odd - min_even

    // Test Case 1: s = "abb"
    unordered_map<char, int> freq;

    //1.
    for(auto c : s){
        freq[c]++;
    }

    // Step 2:
    int min_even = 101;
    int max_odd = -1;

    for(auto f : freq){
        if(f.second % 2 == 0){
            min_even = min(min_even, f.second);
        }

        else{
            max_odd = max(max_odd, f.second);
        }
    }

    return max_odd - min_even;
}