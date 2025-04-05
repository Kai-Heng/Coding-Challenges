#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <sstream>

using namespace std;

long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<long> arr(n, 0);
    long max_val = -1;
    
    for(int i = 0; i < queries.size(); i++){
        int a = queries[i][0];
        int b = queries[i][1];
        int value = queries[i][2];
        
        arr[a-1] += value;
        if(b < n)
            arr[b] -= value;
        
    }
    
    long sum = 0;
    for(auto i : arr){
        sum += i;
        max_val = max(max_val, sum);
    }

    
    return max_val;
}