#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

int getMinimumDeflatedDiscCount(int N, vector<int> R) {
    // Write your code here
    if(R[N-1] < N){
      return -1;
    }
    
    int min_def = 0;
    
    for(int i = N-2; i >= 0; i--){
      if(R[i] >= R[i+1]){
        R[i] = R[i+1] - 1;
        if(R[i] < 1){
          return -1;
        }
        min_def++;
      }
    }
    
    return min_def;
  }