#include <stdlib.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
    int m = mat.size();
    int n = mat[0].size();
    
    vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            prefix[i + 1][j + 1] = mat[i][j] + 
                                   prefix[i][j + 1] + 
                                   prefix[i + 1][j] - 
                                   prefix[i][j];
        }
    }

    vector<vector<int>> answer(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int r1 = max(0, i - k), r2 = min(m - 1, i + k);
            int c1 = max(0, j - k), c2 = min(n - 1, j + k);

            // Adjust indices for prefix matrix (+1 offset)
            answer[i][j] = prefix[r2 + 1][c2 + 1]
                         - prefix[r1][c2 + 1]
                         - prefix[r2 + 1][c1]
                         + prefix[r1][c1];
        }
    }
    
    return answer;
}