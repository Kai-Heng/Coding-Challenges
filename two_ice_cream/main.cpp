#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <sstream>

using namespace std;

vector<int> icecreamParlor(int m, vector<int> arr) {
    vector<int> icecream;
    for(int i = 0; i < arr.size(); i++){
        if(m > arr[i]){
            int remain = m - arr[i];
            auto it = find(arr.begin(),arr.end(), remain);
            
            if(it != arr.end() && distance(arr.begin(), it) != i){
                icecream.push_back(i+1);
                icecream.push_back(distance(arr.begin(), it)+1);
                break;
            }
        }
        
    }
    sort(icecream.begin(), icecream.end());
    return icecream;
}