#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <deque>
#include <set>

using namespace std;

int dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<bool>>& visited) {
    int n = matrix.size();
    int m = matrix[0].size();

    if (i < 0 || j < 0 || i >= n || j >= m || matrix[i][j] == 0 || visited[i][j])
        return 0;

    visited[i][j] = true;
    int count = 1;

    // Explore all 8 directions
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (!(dx == 0 && dy == 0)) {
                count += dfs(i + dx, j + dy, matrix, visited);
            }
        }
    }

    return count;
}

int connectedCell(vector<vector<int>> matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int maxRegion = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] == 1 && !visited[i][j]) {
                int regionSize = dfs(i, j, matrix, visited);
                maxRegion = max(maxRegion, regionSize);
            }
        }
    }

    return maxRegion;
}