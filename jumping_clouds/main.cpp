#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

int jumpingOnClouds(vector<int> c) {
    int i = 0;
    int min_jump = 0;
    while(i < c.size()){
        if(i+2 < c.size() && c[i+2] != 1){
            i += 2;
            min_jump++;
        }
        else if(i+1 < c.size() && c[i+1] != 1){
            i++;
            min_jump++;
        }
        else{
            i++;
        }
    }
    
    return min_jump;
}