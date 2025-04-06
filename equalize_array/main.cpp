#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

int equalizeArray(vector<int> arr) {
    unordered_map<int, int> freq;
    
    for(auto a : arr){
        freq[a]++;
    }
    
    vector<pair<int,int>> sorted(freq.begin(), freq.end());
    
    sort(sorted.begin(), sorted.end(), [](const auto &a, const auto &b){
       return a.second > b.second; 
    });
    
    return arr.size() - sorted[0].second;
}