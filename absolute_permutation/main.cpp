#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

// one number can only occur one time
vector<int> absolutePermutation(int n, int k) {
    vector<int> result;
    unordered_map<int, int> occur;
    for(int i = 1; i <= n; i++){
        if(i > k && occur.count(i-k) == 0){
            result.push_back(i-k);
            occur.insert(pair<int,int>(i-k, 1));
        }
        else{
            
            if(k+i > n){
                result.clear();
                result.push_back(-1);
                return result;
            }
            result.push_back(k+i);
            occur.insert(pair<int,int>(k+i, 1));
            
            
        }
    }
    
    if(result.empty()){
        result.clear();
        result.push_back(-1);
    }
    
    return result;
}