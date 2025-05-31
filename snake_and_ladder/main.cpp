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

static pair<int,int> idToRC(int id, int n) {
    int row = n - 1 - (id - 1) / n;        // how many full rows above bottom
    int col = (id - 1) % n;
    // every other row is reversed (Boustrophedon)
    if ((n - 1 - row) & 1) col = n - 1 - col;
    return {row, col};
}
int snakesAndLadders(vector<vector<int>>& board) {
    int n = board.size();
    vector<int> dist(n * n + 1, -1);        // dist[id] = #rolls to reach id
    queue<int> q;
    dist[1] = 0;
    q.push(1);

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        if (cur == n * n) return dist[cur]; // reached final square

        for (int d = 1; d <= 6 && cur + d <= n * n; ++d) {
            int nxt = cur + d;
            auto [r, c] = idToRC(nxt, n);
            if (board[r][c] != -1)          // snake or ladder
                nxt = board[r][c];

            if (dist[nxt] == -1) {          // not visited yet
                dist[nxt] = dist[cur] + 1;
                q.push(nxt);
            }
        }
    }
    return -1;      
}