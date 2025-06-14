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

vector<int> suggestBackupHosts(int n, vector<vector<int>> resourceSharing) {
    vector<vector<int>> adj(n);
    
    for(auto &e : resourceSharing){
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    vector<unordered_set<int>> has_shared(n);
    
    
    for(int i = 0; i < n; i++){
        has_shared[i] = unordered_set<int>(adj[i].begin(), adj[i].end());
    }
    
    vector<int> offload_targets(n, -1);
    vector<int> cnt(n, 0);
    
    
    for(int i = 0; i < n; i++){
        int bestCnt = -1, bestV = -1;
        
        vector<int> visited;
        
        for(auto a : adj[i]){
            for(auto v : adj[a]){
                if(v == i || has_shared[i].count(v)) continue;
                
                if(cnt[v] == 0) visited.push_back(v);
                cnt[v]++;
                
                if(cnt[v] > bestCnt || (cnt[v] == bestCnt && v < bestV)){
                    bestCnt = cnt[v];
                    bestV = v;
                }
            }
        }
        
        if(bestV == -1){
            for(int v = 0; v < n; v++){
                if(v!=i && !has_shared[i].count(v)){
                    bestV = v;
                    break;
                }
            }
        }
        offload_targets[i] = bestV;
        
        for(int v : visited){
            cnt[v] = 0;
        }
    }
    
    
    return offload_targets;
}