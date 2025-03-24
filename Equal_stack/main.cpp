#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <sstream>

using namespace std;

int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3) {
    int height_h1 = 0;
    int height_h2 = 0;
    int height_h3 = 0;
    
    for(int i = 0; i < h1.size(); i++){
        height_h1 += h1[i];
    }
    
    for(int i = 0; i < h2.size(); i++){
        height_h2 += h2[i];
    }
    for(int i = 0; i < h3.size(); i++){
        height_h3 += h3[i];
    }
    
    reverse(h1.begin(), h1.end());
    reverse(h2.begin(), h2.end());
    reverse(h3.begin(), h3.end());
    
    int min_height = INFINITY;
    min_height = min(min_height, height_h1);
    min_height = min(min_height, height_h2);
    min_height = min(min_height, height_h3);
    
    while(height_h1 != height_h2 || height_h2 != height_h3){
        if(height_h1 != min_height){
            height_h1 -= h1[h1.size()-1];
            h1.pop_back();
        }
        
        if(height_h2 != min_height){
            height_h2 -= h2[h2.size()-1];
            h2.pop_back();
        }
        
        if(height_h3 != min_height){
            height_h3 -= h3[h3.size()-1];
            h3.pop_back();
        }
        
        min_height = min(min_height, height_h1);
        min_height = min(min_height, height_h2);
        min_height = min(min_height, height_h3);
        
    }
    
    return min_height;
}