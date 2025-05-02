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

struct DSU {
    vector<int> p, sz;
    DSU(int n): p(n), sz(n,1) { iota(p.begin(), p.end(), 0); }
    int find(int x){ return p[x]==x? x : p[x]=find(p[x]); }
    void unite(int a,int b){
        a=find(a); b=find(b);
        if(a==b) return;
        if(sz[a]<sz[b]) swap(a,b);
        p[b]=a;  sz[a]+=sz[b];
    }
};
vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
    DSU dsu(n);

    /* union consecutive indices if their value gap ≤ maxDiff */
    for(int i=0;i+1<n;++i)
        if(nums[i+1]-nums[i] <= maxDiff)
            dsu.unite(i,i+1);

    vector<bool> ans;
    ans.reserve(queries.size());

    for(auto& q: queries)
        ans.push_back(dsu.find(q[0]) == dsu.find(q[1]));

    return ans;
}