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


int computeMinimumLatency(int route_nodes, vector<int> route_from, vector<int> route_to, int startGateway, int endGateway, vector<int> monitors) {
    vector<vector<int>> g(route_nodes);
    for(int i = 0; i < route_from.size(); i++){
        int u = route_from[i] - 1;
        int v = route_to[i] - 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    vector<char> required(route_nodes, 0);
    required[startGateway-1] = 1;
    required[endGateway-1] = 1;
    for(int x : monitors) required[x-1] = 1;
    int totalReq = 2 + monitors.size();
    
    long long edges = 0;
    
    vector<int> parent(route_nodes, -1);
    vector<int> order;
    order.push_back(0);
    for(int i = 0; i < route_nodes; i++){
        int u = order[i];
        for(int v : g[u]){
            if(v != parent[u]){
                parent[v] = u;
                order.push_back(v);
            }
        }
    }
    
    vector<int> cnt(route_nodes, 0);
    for(int i = route_nodes-1; i >= 0; i--){
        int u = order[i];
        cnt[u] += required[u];
        if(parent[u] != -1){
            if(cnt[u] > 0 && cnt[u] < totalReq)
                edges++;
            cnt[parent[u]] += cnt[u];
        }
    }
    
    vector<int> dist(route_nodes, -1);
    deque<int> q = {startGateway-1};
    dist[startGateway-1] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop_front();
        for(int v : g[u]){
            if(dist[v] == -1){
                dist[v] = dist[u] + 1;
                q.push_back(v);
            }
        }
    }
    int distSE = dist[endGateway-1];
    
    return int(2*edges-distSE);
}