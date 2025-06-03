#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <queue>
#include <stack>
#include <math.h>
#include <numeric>

using namespace std;

int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
    int n = status.size();
    vector<char> haveBox(n, 0), haveKey(n, 0), open(n, 0);
    queue<int> q;
    for (int b : initialBoxes) {
        haveBox[b] = 1;
        q.push(b);
    }

    long long ans = 0;

    while (!q.empty()) {
        int b = q.front(); q.pop();

        if (!open[b] && status[b]) open[b] = 1; // directly open

        if (!open[b]) continue;                 // still closed

        ans += candies[b];
        candies[b] = 0;                         // take only once
        open[b] = 0;                            // mark processed

        // new keys
        for (int k : keys[b]) {
            if (!haveKey[k]) {
                haveKey[k] = 1;
                if (haveBox[k])
                    open[k] = 1, q.push(k);
            }
        }
        // new boxes
        for (int nb : containedBoxes[b]) {
            if (!haveBox[nb]) {
                haveBox[nb] = 1;
                if (haveKey[nb]) open[nb] = 1;
                q.push(nb);
            }
        }
    }
    return (int)ans;
}