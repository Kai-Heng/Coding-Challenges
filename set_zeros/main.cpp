#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

void down(vector<vector<int>>& matrix, int i, int j){
    if(i >= matrix.size() || i < 0 || j < 0 || j >= matrix[i].size()) return;

    matrix[i][j] = 0;
    down(matrix, i+1, j);
}

void up(vector<vector<int>>& matrix, int i, int j){
    if(i >= matrix.size() || i < 0 || j < 0 || j >= matrix[i].size()) return;

    matrix[i][j] = 0;
    up(matrix, i-1, j);
}

void left(vector<vector<int>>& matrix, int i, int j){
    if(i >= matrix.size() || i < 0 || j < 0 || j >= matrix[i].size()) return;

    matrix[i][j] = 0;
    left(matrix, i, j-1);
}

void right(vector<vector<int>>& matrix, int i, int j){
    if(i >= matrix.size() || i < 0 || j < 0 || j >= matrix[i].size()) return;

    matrix[i][j] = 0;
    right(matrix, i, j+1);
}

void setZeroes(vector<vector<int>>& matrix) {
    vector<pair<int,int>> zeros;

    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++){
            if(matrix[i][j] == 0) zeros.push_back({i,j});
        }
    }

    for(auto a : zeros){
        down(matrix, a.first, a.second);
        up(matrix, a.first, a.second);
        left(matrix, a.first, a.second);
        right(matrix, a.first, a.second);
    }
}