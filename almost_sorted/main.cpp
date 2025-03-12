#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

void almostSorted(vector<int> arr) {
    vector<int> arr_sorted(arr.begin(), arr.end());
    sort(arr_sorted.begin(), arr_sorted.end());
    
    vector<int> indices;
    
    for(int i = 0; i < arr.size(); i++){
        if(arr_sorted[i] != arr[i]){
            indices.push_back(i);
        }
    }
    
    string s = "";
    if(indices.size() > 2){
        reverse(arr.begin()+indices[0], arr.begin()+indices[indices.size()-1] + 1);
        s += "reverse " + to_string(indices[0]+1) + " " + to_string(indices[indices.size()-1]+1);
    }
    else{
        swap(arr[indices[0]], arr[indices[1]]);
        s += "swap " + to_string(indices[0]+1) + " " + to_string(indices[1]+1);
    }
    
    if(arr_sorted == arr){
        cout << "yes" << endl;
        cout << s << endl;
    }
    else{
        cout << "no" << endl;
    }
}