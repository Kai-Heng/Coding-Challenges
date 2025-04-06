#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

int beautifulTriplets(int d, vector<int> arr) {
    unordered_map<int,int> freq;
    int triplet = 0;
    for(auto a : arr){
        freq[a]++;
    }
    
    
    for(auto f : arr){
        int i = f + d;
        if(freq.count(i) != 0){
            int j = i + d;
            if(freq.count(j) != 0){
                triplet++;
            }
        }
    }
    return triplet;
}