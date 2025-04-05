#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <sstream>

using namespace std;

vector<int> dynamicArray(int n, vector<vector<int>> queries) {
    vector<int> arr;
    vector<vector<int>> arr_2d(n);
    
    int lastAnswer = 0;
    
    for(int i = 0; i < queries.size(); i++){
        int type = queries[i][0];
        int x = queries[i][1];
        int y = queries[i][2];
        
        auto idx = (x ^ lastAnswer) % n;
        switch (type) {
            case 1:
                arr_2d[idx].push_back(y);
                break;
                
            case 2:
                lastAnswer = arr_2d[idx][y % arr_2d[idx].size()];
                arr.push_back(lastAnswer);
                break;
            default:
                break;
        }
    }
    
    return arr;
}