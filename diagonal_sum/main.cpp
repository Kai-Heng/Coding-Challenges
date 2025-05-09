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

int diagonalSum(vector<vector<int>>& mat) {
    int left = 0;
    int right = mat[0].size()-1;
    int row = 0;
    int sum = 0;
    
    while(row < mat.size()){
        if(left == right){
            sum += mat[row][left];
        }
        else{
            sum += mat[row][left] + mat[row][right];
        }
        left++;
        right--;
        row++;
    }
    
    return sum;
}