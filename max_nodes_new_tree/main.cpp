#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
    int n1 = edges1.size()+1, n2 = edges2.size()+1;
    if (k == 0)
        return vector<int>(n1, 1);   // ← shortest‑path bound makes bridge useless

    auto bfs=[&](int n, auto& edges, int start, int lim){
        vector<int>d(n, -1); queue<int>q; q.push(start); d[start]=0;
        int cnt=1;
        while(!q.empty()){
            int v=q.front();q.pop();
            for(int nb:edges[v])
                if(d[nb]==-1 && d[v]+1<=lim){
                    d[nb]=d[v]+1; ++cnt; q.push(nb);
                }
        }
        return cnt;
    };

    /* build adjacency */
    vector<vector<int>> g1(n1),g2(n2);
    for(auto &e:edges1){g1[e[0]].push_back(e[1]);g1[e[1]].push_back(e[0]);}
    for(auto &e:edges2){g2[e[0]].push_back(e[1]);g2[e[1]].push_back(e[0]);}

    /* all‑pairs balls inside tree‑2 */
    int best2=0;
    for(int x=0;x<n2;++x)
            best2=max(best2,bfs(n2,g2,x,k-1));

    /* answers */
    vector<int> ans(n1);
    for(int u=0;u<n1;++u)
            ans[u]=bfs(n1,g1,u,k)+best2;

    return ans;
}