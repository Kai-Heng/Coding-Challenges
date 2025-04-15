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

int pairs(int k, vector<int> arr) {
    set<int> s;
    int numOfPairs = 0;
    
    for(auto a : arr){
        s.insert(a);
    }
    
    for(auto i : s){
        if(i-k >= 0 && s.count(i-k) != 0){
            numOfPairs++;
        }
    }
    
    return numOfPairs;
}