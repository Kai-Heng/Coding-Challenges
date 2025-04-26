#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <unordered_set>
#include <sstream>

using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> pascal(numRows);
    
    pascal[0].push_back(1);
    for(int i = 1; i < numRows; i++){
        int j = 0;
        while(j < i+1){
            if(j-1 >=0 && j < pascal[i-1].size())
                pascal[i].push_back(pascal[i-1][j]+pascal[i-1][j-1]);
            else if(j-1 < 0){
                pascal[i].push_back(pascal[i-1][j]);
            }
            else if(j >= pascal[i-1].size()){
                pascal[i].push_back(pascal[i-1][j-1]);
            }
            j++;
        }
    }
    
    return pascal;
}