#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <unordered_map>
#include <numeric>
#include <algorithm>
#include <math.h>

using namespace std;

int minimumDeletions(string word, int k) {
    unordered_map<char, int> freq;
    for(auto &c : word){
        freq[c]++;
    }
    int min_deletion = word.size();

    for(auto &[_,x] : freq){
        int deletion = 0;
        for(auto &[_,y] : freq){
            if(y < x){
                deletion += y;
            }
            else if(y > x + k){
                deletion += y - x - k;
            }
        }
        min_deletion = min(min_deletion, deletion);
    }
    
    return min_deletion;
}