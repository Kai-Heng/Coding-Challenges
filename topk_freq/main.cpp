#include <stdlib.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int> freq;
    
    for(auto w : words){
        freq[w]++;
    }
    
    vector<pair<string, int>> sorted(freq.begin(), freq.end());
    
    sort(sorted.begin(), sorted.end(), [](const auto &a, const auto &b){
      if(a.second > b.second){
          return true;
      }
    if(a.second == b.second){
            return a.first < b.first;
        }
        
        return false;
    });
    
    vector<string> ans;
    for(auto s : sorted){
        if(ans.size() < k){
            ans.push_back(s.first);
        }
        else{
            break;
        }
    }
    
    return ans;
}