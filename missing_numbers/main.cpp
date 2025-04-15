#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <deque>
#include <set>

using namespace std;

vector<int> missingNumbers(vector<int> arr, vector<int> brr) {
    map<int, int> a;
    map<int, int> b;
    vector<int> missing_nums;
    
    for(int i = 0; i < brr.size(); i++){
        if(i < arr.size()){
            a[arr[i]]++;
        }
        b[brr[i]]++;
    }
    
    for(auto freq : b){
        if(a.count(freq.first) == 0){
            missing_nums.push_back(freq.first);
        }
        else if(a[freq.first] != freq.second){
            missing_nums.push_back(freq.first);
        }
    }
    
    return missing_nums;
}