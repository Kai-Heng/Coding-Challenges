#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

void matrixRotation(vector<vector<int>> matrix, int r) {
    int m = matrix.size();
    int n = matrix[0].size();
    int layers = min(m, n) / 2;

    for (int layer = 0; layer < layers; ++layer) {
        vector<int> vals;

        int top = layer, bottom = m - 1 - layer;
        int left = layer, right = n - 1 - layer;

        // Top
        for (int j = left; j < right; ++j) vals.push_back(matrix[top][j]);
        // Right
        for (int i = top; i < bottom; ++i) vals.push_back(matrix[i][right]);
        // Bottom
        for (int j = right; j > left; --j) vals.push_back(matrix[bottom][j]);
        // Left
        for (int i = bottom; i > top; --i) vals.push_back(matrix[i][left]);

        int len = vals.size();
        int rot = r % len;
        vector<int> rotated(len);
        for (int i = 0; i < len; ++i)
            rotated[i] = vals[(i + rot) % len];

        int idx = 0;
        // Put values back
        for (int j = left; j < right; ++j) matrix[top][j] = rotated[idx++];
        for (int i = top; i < bottom; ++i) matrix[i][right] = rotated[idx++];
        for (int j = right; j > left; --j) matrix[bottom][j] = rotated[idx++];
        for (int i = bottom; i > top; --i) matrix[i][left] = rotated[idx++];
    }

    // Output result
    for (const auto& row : matrix) {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }
}