#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

void dfs(vector<vector<int>>& grid, int i, int j, int n) {
    if (i < 0 || j < 0 || i >= n || j >= n || grid[i][j] != 0)
        return;

    grid[i][j] = 1;

    dfs(grid, i + 1, j, n);
    dfs(grid, i - 1, j, n);
    dfs(grid, i, j + 1, n);
    dfs(grid, i, j - 1, n);
}
int regionsBySlashes(vector<string>& grid) {
    int n = grid.size();
    int size = n * 3;
    vector<vector<int>> expanded(size, vector<int>(size, 0));

    // Expand slashes into a 3x3 block
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '/') {
                expanded[i * 3][j * 3 + 2] = 1;
                expanded[i * 3 + 1][j * 3 + 1] = 1;
                expanded[i * 3 + 2][j * 3] = 1;
            } else if (grid[i][j] == '\\') {
                expanded[i * 3][j * 3] = 1;
                expanded[i * 3 + 1][j * 3 + 1] = 1;
                expanded[i * 3 + 2][j * 3 + 2] = 1;
            }
        }
    }

    // DFS to count regions
    int regions = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (expanded[i][j] == 0) {
                dfs(expanded, i, j, size);
                regions++;
            }
        }
    }

    return regions;
}