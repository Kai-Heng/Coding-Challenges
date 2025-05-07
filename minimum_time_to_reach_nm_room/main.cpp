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

using pii = pair<int,int>;
int minTimeToReach(vector<vector<int>>& moveTime) {
    const int n = moveTime.size();
    const int m = moveTime[0].size();
    const int target = n * m - 1;
    const int DIRS[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    const long long INF = 4e18;

    auto encode = [m](int r, int c){ return r * m + c; };
    auto inGrid = [n,m](int r, int c){
        return r>=0 && r<n && c>=0 && c<m;
    };

    vector<long long> dist(n*m, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[0] = 0;                             // start at (0,0) t = 0
    pq.emplace(0, 0);

    while (!pq.empty()) {
        auto [t, v] = pq.top(); pq.pop();
        if (v == target) return (int)t;      // earliest arrival at goal
        if (t != dist[v]) continue;          // stale

        int r = v / m, c = v % m;
        for (auto d : DIRS) {
            int nr = r + d[0], nc = c + d[1];
            if (!inGrid(nr, nc)) continue;
            int u = encode(nr, nc);

            long long depart = max<long long>(t, moveTime[nr][nc]); // wait if needed
            long long arrive = depart + 1;                          // move takes 1 s
            if (arrive < dist[u]) {
                dist[u] = arrive;
                pq.emplace(arrive, u);
            }
        }
    }
    return -1;
}