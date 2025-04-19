#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <set>

using namespace std;

int closedIsland(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int count = 0;
    
    function<bool(int, int)> dfs = [&](int i, int j) {
        // If out of bounds → not closed
        if (i < 0 || j < 0 || i >= n || j >= m)
            return false;
        if (grid[i][j] == 1) return true; // water

        grid[i][j] = 1; // mark as visited

        bool top = dfs(i - 1, j);
        bool bottom = dfs(i + 1, j);
        bool left = dfs(i, j - 1);
        bool right = dfs(i, j + 1);

        return top && bottom && left && right;
    };
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 0 && dfs(i, j)) {
                count++;
            }
        }
    }
    
    return count;
}