#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <deque>
#include <unordered_set>

using namespace std;

long long gridlandMetro(long long n, long long m, int k, vector<vector<long long>> track) {
    long long empty_cell = n*m;
    unordered_map<long long, vector<pair<long long, long long>>> simplified;
    
    for(int i = 0; i < track.size(); i++){
        long long r = track[i][0]-1;
        long long s = track[i][1];
        long long e = track[i][2];
        if(simplified[r].empty()){
            simplified[r].push_back({s,e});
        }
        else{
            int j = 0;
            while(j < simplified[r].size() && simplified[r][j].second < s){
                j++;
            }
            if(j >= simplified[r].size()){
                simplified[r].push_back({s, e});
            }
            else{
                if(simplified[r][j].first > s){
                    simplified[r][j].first = s;
                }
                
                if(simplified[r][j].second < e){
                    simplified[r][j].second = e;
                }
            }
        }
    }
    
    for(auto s : simplified){
        for(auto a : s.second){
            empty_cell -= (a.second - a.first + 1);
        }
    }
    
    return empty_cell;
}