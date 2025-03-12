#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

long long getMinCodeEntryTime(int N, int M, vector<int> C) {
    // Write your code here
    long long total_time = 0;
    int prev = 1;
    for(int i = 0; i < M; i++){
      if(prev < C[i]){
        total_time += min(prev+N-C[i], abs(prev - C[i]));
      }
      else{
        total_time += min(N+C[i]-prev, abs(prev - C[i]));
      }
      
      prev = C[i];
                  
    }
    cout << total_time << endl;
    return total_time;
  }