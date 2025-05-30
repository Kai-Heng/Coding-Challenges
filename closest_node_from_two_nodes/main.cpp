#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

void fillDist(int start, const vector<int>& edges, vector<int>& dist) {
    int d = 0;
    while (start != -1 && dist[start] == -1) {
        dist[start] = d++;
        start = edges[start];
    }
}

int closestMeetingNode(vector<int>& edges, int node1, int node2) {
    int n = edges.size();
    vector<int> dist1(n, -1), dist2(n, -1);

    fillDist(node1, edges, dist1);
    fillDist(node2, edges, dist2);

    int bestIdx = -1;
    long long bestMax = LLONG_MAX;

    for (int v = 0; v < n; ++v) {
        if (dist1[v] == -1 || dist2[v] == -1) continue;

        long long cur = max(dist1[v], dist2[v]);
        if (cur < bestMax || (cur == bestMax && v < bestIdx)) {
            bestMax = cur;
            bestIdx = v;
        }
    }
    return bestIdx;
}