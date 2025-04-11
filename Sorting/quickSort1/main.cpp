#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

vector<int> quickSort(vector<int> arr) {
    int pivot = arr[0];
    vector<int> left;
    vector<int> right;
    for(int i = 1; i < arr.size(); i++){
        if(arr[i] <= pivot){
            left.push_back(arr[i]);
        }
        else{
            right.push_back(arr[i]);
        }
    }
    
    vector<int> sorted(arr.size());
    
    sorted = left;
    sorted.push_back(pivot);
    sorted.insert(sorted.end(),right.begin(), right.end());
    
    return sorted;
}