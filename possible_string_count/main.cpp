#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <unordered_map>
#include <numeric>
#include <algorithm>
#include <math.h>
#include <unordered_set>

using namespace std;

int possibleStringCount(string word) {
    unordered_map<char, int> f;
    char prev = '\0';
    
    for(auto w : word){
        f[w]++;

        if(w != prev){
            f[w]--;
        }
        prev = w;
    }

    int ans = 1;
    for(auto i : f){
        ans += i.second;
    }

    return ans;
}