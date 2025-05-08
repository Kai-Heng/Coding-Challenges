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

using Node = pair<long long,int>;                 // (time, id)

int minTimeToReach(vector<vector<int>>& moveTime) {
    const int n = moveTime.size(), m = moveTime[0].size();
    const int DIR[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    const long long INF = 4e18;
    auto in = [&](int r,int c){ return 0<=r&&r<n&&0<=c&&c<m; };
    auto id  = [&](int r,int c,int p){ return ((r*m+c)<<1)|p; };

    vector<long long> dist(n*m*2, INF);
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    dist[id(0,0,0)] = 0;
    pq.emplace(0, id(0,0,0));

    while (!pq.empty()) {
        auto [t, v] = pq.top(); pq.pop();
        if (t != dist[v]) continue;

        int cell = v >> 1, p = v & 1;
        int r = cell / m, c = cell % m;
        if (r == n-1 && c == m-1) return (int)t;          // goal reached

        long long step = p ? 2 : 1;
        for (auto d : DIR) {
            int nr = r + d[0], nc = c + d[1];
            if (!in(nr,nc)) continue;

            long long depart = max<long long>(t, moveTime[nr][nc]);
            long long arrive = depart + step;
            int     nid     = id(nr,nc, p^1);

            if (arrive < dist[nid]) {
                dist[nid] = arrive;
                pq.emplace(arrive, nid);
            }
        }
    }
    return -1;              // should not happen per problem statement
}