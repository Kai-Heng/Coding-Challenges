#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

int surfaceArea(vector<vector<int>> A) {
    vector<int> row_surface_unit(A[0].size(), 0);
    int surface_unit = 0;
    for(int i = 0; i < A[0].size(); i++){
        for(int j = 0; j < A.size(); j++){
            cout << A[j][i] << " ";
            if(j == 0){
                row_surface_unit[i] += A[j][i]*4 + 2*1;
            } 
            else{
                 row_surface_unit[i] += (abs(A[j][i] - A[j-1][i]) + A[j][i]*3 + 2*1) - A[j-1][i];
            }
        }
        
        surface_unit += row_surface_unit[i];
        cout << endl;
        cout << row_surface_unit[i] << endl;
    }
    
    int col_hidden_unit = 0;
    for(int i = 0; i < A.size(); i++){
        for(int j = 1; j < A[i].size(); j++){
            if(A[i][j] >= A[i][j-1]){
                col_hidden_unit += A[i][j-1]*2;
            }
            else{
                col_hidden_unit += A[i][j]*2;
            }
        }
    }
    
    // int total_surface_unit = 0;
    // int total_hidden_surface_unit = 0;
    
    
    // for(int i = 0; i < A[0].size(); i++){
    //     int left = 0;
    //     int right = A.size()-1;
    //     while(left <= right){
    //         if(left == right){
    //             total_surface_unit += A[left][i]*4 + 2*1;
    //         }
    //         else{
    //             total_surface_unit += A[left][i]*4 + 2*1;
    //             total_surface_unit += A[right][i]*4 + 2*1;
    //         }
            
    //         left++;
    //         right--;
    //     }
        
    //     // cout << total_surface_unit << endl;
    // }
    
    // for(int i = 0; i < A[0].size(); i++){
    //     int left = 1;
    //     int right = A.size()-2;
    //     while(left <= right){
            
    //         if(A[left][i] >= A[left-1][i])
    //             total_hidden_surface_unit += A[left-1][i]*2;
    //         else{
    //             total_hidden_surface_unit += A[left][i]*2;
    //         }
            
    //         if(A[right][i] >= A[right+1][i])
    //             total_hidden_surface_unit += A[right+1][i]*2;
    //         else{
    //             total_hidden_surface_unit += A[right][i]*2;
    //         }
            
    //         left++;
    //         right--;
            
    //         cout << total_hidden_surface_unit << endl;
    //     }
    // }
    
    // for(int i = 0; i < A.size(); i++){
    //     int left = 0;
    //     int right = A[0].size()-1;
    //     while(left < right){
    //         if(A[i][left] >= A[i][left+1])
    //             total_hidden_surface_unit += A[i][left+1]*2;
    //         else{
    //             total_hidden_surface_unit += A[i][left]*2;
    //         }
            
    //         if(A[i][right] >= A[i][right-1])
    //             total_hidden_surface_unit += A[i][right-1]*2;
    //         else{
    //             total_hidden_surface_unit += A[i][right]*2;
    //         }
            
    //         left++;
    //         right--;
            
    //         cout << total_hidden_surface_unit << endl;
    //     }
    // }
    
    
    
    return surface_unit - col_hidden_unit;
}
