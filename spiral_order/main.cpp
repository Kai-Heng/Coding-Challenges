#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    
    
    vector<int> results;

    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;

    while (top <= bottom && left <= right) {
        // Top row
        for (int j = left; j <= right; ++j)
            results.push_back(matrix[top][j]);
        ++top;

        // Right column
        for (int i = top; i <= bottom; ++i)
            results.push_back(matrix[i][right]);
        --right;

        // Bottom row (if not already traversed)
        if (top <= bottom) {
            for (int j = right; j >= left; --j)
                results.push_back(matrix[bottom][j]);
            --bottom;
        }

        // Left column (if not already traversed)
        if (left <= right) {
            for (int i = bottom; i >= top; --i)
                results.push_back(matrix[i][left]);
            ++left;
        }
    }

    return results;
        
}