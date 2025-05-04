#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <set>
#include <random>

using namespace std;

int numEquivDominoPairs(vector<vector<int>>& dominoes) {
    int n = dominoes.size();
    int pairs = 0;
    unordered_map<string, int> freq;
    for(int i = 0; i < n; i++){
        string temp = "";

        if(dominoes[i][0] > dominoes[i][1]){
            temp += to_string(dominoes[i][1]) + "," + to_string(dominoes[i][0]);
        }
        else{
            temp += to_string(dominoes[i][0]) + "," + to_string(dominoes[i][1]);
        }

        freq[temp]++;
    }

    for(auto f : freq){
        if(f.second > 1){
            pairs += f.second*(f.second-1)/2;
        }
    }

    return pairs;
}