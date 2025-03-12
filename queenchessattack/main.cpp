#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <string>

using namespace std;


/*
 * Complete the 'queensAttack' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n board structure nxn
 *  2. INTEGER k number of obstacle
 *  3. INTEGER r_q y
 *  4. INTEGER c_q x
 *  5. 2D_INTEGER_ARRAY obstacles
 */

 int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    vector<vector<char>> board(n, vector<char>(n, 'V'));
    int allPossibleAttack = 0;
    board[r_q - 1][c_q - 1] = 'Q';
    allPossibleAttack = n*n;
    allPossibleAttack -= 1; // because of queen
    for(int i = 0; i < k; i++){
        int count = 0;
        // same row
        if(obstacles[i][0] == r_q){
            //Disable left
            if(obstacles[i][1] < c_q){
                for(int j = obstacles[i][1]-1; j >=0; j--){
                    board[obstacles[i][0]-1][j] = 'E';
                    count++;
                }
            }
            
            // Disable right
            else{
                for(int j = obstacles[i][1]-1; j < n; j++){
                    board[obstacles[i][0]-1][j] = 'E';
                    count++;
                }
            }
            
            
        }
        
        // Same column
        else if(obstacles[i][1] == c_q){
            
            // Disable top
            if(obstacles[i][0] > r_q){
                for(int j = obstacles[i][0]-1; j < n; j++){
                    board[j][obstacles[i][1]-1] = 'E';
                    count++;
                }
            }
            
            // Disable bottom
            else{
                for(int j = obstacles[i][0]-1; j >= 0; j--){
                    board[j][obstacles[i][1]-1] = 'E';
                    count++;
                }
            }
        }
        else{
            board[obstacles[i][0]-1][obstacles[i][1]-1] = 'E';
            count++;
        }
        allPossibleAttack -= count;
        cout << allPossibleAttack << endl;
    }
    for(int i= 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i+1 != r_q && j+1 != c_q && board[i][j] != 'E'){
                board[i][j] = 'T';
                allPossibleAttack--;
            }
        }
    }
    
       for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<< board[i][j];
        }
        cout << endl;
    }
    
    for(int i = 1; i < n; i++){
        if(r_q + i <= n && c_q + i <= n && board[r_q+i-1][c_q+i-1] == 'T'){
            board[r_q+i-1][c_q+i-1] = 'C';
            allPossibleAttack++;
        }
        if(r_q + i <= n && c_q - i >= 0 && board[r_q+i-1][c_q-i-1] == 'T'){
            board[r_q+i-1][c_q-i-1] = 'C';
            allPossibleAttack++;
        }
        
        if((r_q + i > n && c_q + i > n )&& (r_q + i > n && c_q - i < 0)) break;
    }
    
    
    
    for(int i = 1; i < n; i++){
        if(r_q - i > 0 && c_q + i <= n && board[r_q-i-1][c_q+i-1] == 'T'){
            board[r_q-i-1][c_q+i-1] = 'C';
            allPossibleAttack++;
        }
        if(r_q - i > 0 && c_q - i >= 0 && board[r_q-i-1][c_q-i-1] == 'T'){
            board[r_q-i-1][c_q-i-1] = 'C';
            allPossibleAttack++;
        }
        
        if((r_q - i <= 0 && c_q + i > n )&& (r_q - i <= 0 && c_q - i < 0)) break;
    }
    
    cout<< "Breakpoint: -----------"<<endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<< board[i][j];
        }
        cout << endl;
    }
    // allPossibleAttack = 2*n;
    // if(r_q % 2 == 0 && c_q % 2 == 1){
    //     allPossibleAttack += 
    // }
    return allPossibleAttack;
}

int main(){
    cout << queensAttack(8, 0, 1, 1, {}) << endl;
}