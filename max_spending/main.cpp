#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

int getMoneySpent(vector<int> keyboards, vector<int> drives, int b) {
    /*
     * Write your code here.
     */
     int max_spending = -1;
     for(int i = 0; i < keyboards.size(); i++){
        if(keyboards[i] >= b) continue;
        for(int j = 0; j < drives.size(); j++){
            if(keyboards[i] + drives[j] <= b){
                max_spending = max(max_spending, keyboards[i] + drives[j]);
            }
        }
     }
     
     return max_spending;

}