#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

vector<string> detonateBombs(const vector<string>& grid) {
    int rows = grid.size(), cols = grid[0].size();
    vector<vector<char>> newGrid(rows, vector<char>(cols, 'O'));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 'O') {
                newGrid[i][j] = '.';
                if (i > 0) newGrid[i - 1][j] = '.';  // Up
                if (i < rows - 1) newGrid[i + 1][j] = '.';  // Down
                if (j > 0) newGrid[i][j - 1] = '.';  // Left
                if (j < cols - 1) newGrid[i][j + 1] = '.';  // Right
            }
        }
    }

    vector<string> result;
    for (int i = 0; i < rows; i++) {
        result.push_back(string(newGrid[i].begin(), newGrid[i].end()));
    }
    return result;
}

vector<string> bomberMan(int n, vector<string> grid) {
    if (n == 1) return grid;  // No change at t = 1

    vector<string> fullBombs(grid.size(), string(grid[0].size(), 'O'));  // Grid with all bombs
    vector<string> new_grid(grid.begin(), grid.end());
    if (n % 2 == 0) return fullBombs;  // t = 2 -> Full grid
    if (n % 4 == 1){
        return detonateBombs(detonateBombs(grid));  // t = 4 -> 2nd explosion
    }
    
    return detonateBombs(grid);  // t = 3 -> 1st explosion
}