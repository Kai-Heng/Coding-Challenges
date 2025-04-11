#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

vector<int> closestNumbers(vector<int> arr) {
    sort(arr.begin(), arr.end());
    
    int diff = INFINITY;
    vector<int> two_nums;
    
    for(int i = 0; i < arr.size()-1; i++){
        if(abs(arr[i]-arr[i+1]) < abs(diff)){
            diff = arr[i] - arr[i+1];
        }
    }
    
    for(int i = 0; i < arr.size()-1; i++){
        if(abs(arr[i]-arr[i+1]) == abs(diff)){
            two_nums.push_back(arr[i]);
            two_nums.push_back(arr[i+1]);
        }
    }
    
    
    return two_nums;
}