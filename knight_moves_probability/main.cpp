#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <unordered_set>

using namespace std;

vector<vector<vector<double>>> memo;
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

double dfs(int n, int k, int row, int col) {
    if (row < 0 || row >= n || col < 0 || col >= n) return 0.0;
    if (k == 0) return 1.0;

    if (memo[row][col][k] != -1.0) return memo[row][col][k];

    double prob = 0.0;
    for (int i = 0; i < 8; i++) {
        prob += dfs(n, k - 1, row + dx[i], col + dy[i]) / 8.0;
    }

    return memo[row][col][k] = prob;
}

double knightProbability(int n, int k, int row, int column) {
    memo = vector<vector<vector<double>>>(n, vector<vector<double>>(n, vector<double>(k + 1, -1.0)));
    return dfs(n, k, row, column);
}