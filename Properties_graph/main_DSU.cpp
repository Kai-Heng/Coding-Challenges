#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <unordered_set>
#include <numeric>

using namespace std;

// Brute force approach
int intersect(vector<int>& a, vector<int>& b) {
    unordered_set<int> setA(a.begin(), a.end());
    int count = 0;
    for (int num : b) {
        if (setA.count(num)) {
            count++;
            setA.erase(num); // ensures distinct
        }
    }
    return count;
}

int find(vector<int>& parent, int x) {
    if (parent[x] != x)
        parent[x] = find(parent, parent[x]);
    return parent[x];
}

void unite(vector<int>& parent, vector<int>& rank, int x, int y) {
    int px = find(parent, x);
    int py = find(parent, y);
    if (px != py) {
        if (rank[px] < rank[py]) swap(px, py);
        parent[py] = px;
        if (rank[px] == rank[py]) rank[px]++;
    }
}

int numberOfComponents(vector<vector<int>>& properties, int k) {
    int n = properties.size();
    vector<int> parent(n), rank(n, 0);
    iota(parent.begin(), parent.end(), 0); // parent[i] = i

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (intersect(properties[i], properties[j]) >= k) {
                unite(parent, rank, i, j);
            }
        }
    }

    unordered_set<int> unique_roots;
    for (int i = 0; i < n; ++i)
        unique_roots.insert(find(parent, i));

    return unique_roots.size();
}