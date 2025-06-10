#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <set>
#include <random>
#include <stack>
#include <unordered_set>
#include <queue>

using namespace std;

void rotate(vector<vector<int>>& matrix) {
    // Notes: given n x n 2D matrix, DO NOT allocate another 2D matrix and do the rotation
    // Rotate 90 degrees
    // 1. Reverse each column [vertically]
    // 2. Swap index base on i,j

    // First row will become last column
    // 1 2
    // 3 4

    // Expected:
    // 3 1
    // 4 2

    /**
    Step 1
    for i in matrix[0].length:
        up = 0;
        bottom = matrix.length()-1;
        while(up < bottom):
            swap(matrix[up][i], matrix[bottom][i])
            up++;
            bottom--;
    
    // 3 4 [0][0] [0][1]
    // 1 2 [1][0] [1][1] 

    Step 2:
    for i in matrix.length:
        for j = i in matrix[i]:
            swap(matrix[i][j], matrix[j][i]);

    i j
    0 0 
    0 1
    1 0
    // 3 4 [0][0] [0][1]
    // 1 2 [1][0] [1][1] 

    */

    /**
    k = 4-1 = 3

    
    Inner loop:
    i j k
    0 0 3
    matrix[0][0] swap with matrix[0][3]
    0 1 3
    matrix[0][1] swap with matrix[1][3]
    0 2 3
    matrix[0][2] swap with matrix[2][3]


    Expected:
    [15,13,2,5]
    [14,3,4,1]
    [12,6,8,9]
    [16,7,10,11]
    */

    for(int i = 0; i < matrix[0].size(); i++){
        int up = 0;
        int bottom = matrix.size()-1;

        while(up < bottom){
            swap(matrix[up][i], matrix[bottom][i]);
            up++;
            bottom--;
        }
    }

    for(int i = 0; i < matrix.size(); i++){
        for(int j = i; j < matrix[i].size(); j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }

}