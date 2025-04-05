#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <sstream>

using namespace std;

int hourglassSum(vector<vector<int>> arr) {
    int n = arr.size();
    vector<vector<int>> row_sum(n, vector<int>(arr[0].size()));
    int max_sum = -INFINITY;
    
    for(int i = 0; i < arr.size(); i++){
        for(int j = 1; j < arr[i].size()-1; j++){
            row_sum[i][j] = arr[i][j-1] + arr[i][j] + arr[i][j+1];
        }
    }
    
    for(int i = 1; i < arr.size()-1; i++){
        for(int j = 1; j < arr[i].size()-1; j++){
            max_sum = max(max_sum, row_sum[i-1][j] + arr[i][j] +row_sum[i+1][j]);
        }
    }
    
    return max_sum;
}