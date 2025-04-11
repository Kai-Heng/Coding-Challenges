#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

vector<int> countingSort(vector<int> arr) {
    vector<int> result(100);
    vector<int> sorted;
    for(auto a : arr){
        result[a]++;
    }
    for(int i = 0; i < result.size(); i++){
        if(result[i] != 0){
            for(int j = 0; j < result[i]; j++){
                sorted.push_back(i);
            }
        }
    }
    return sorted;
}