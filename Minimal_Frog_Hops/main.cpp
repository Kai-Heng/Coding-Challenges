#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

long long getSecondsRequired(long long N, int F, vector<long long> P) {
    // Write your code here
    long long mn = *min_element(P.begin(), P.end());
  
    return N - mn;


    /**
    // Work perfectly with small N, O(N^2)
    vector<int> tracker(N+1, 0);
    
    for(int i = 0; i < F; i++){
      tracker[P[i]]++;
    }
    
  
    long long seconds = 0;

    // for(auto a : tracker){
    //   cout << a << " ";
    // }
    // cout << endl;
    for(int i = 0; i < tracker.size(); i++){
      if(tracker[i] == 0){
        continue;
      }
      for(int j = i+1; j < tracker.size(); j++){
        if(j == N){
          tracker[i] = 0;
          seconds++;
        }
        else if(tracker[j] == 0){
          tracker[i] = 0;
          tracker[j] = 1;
          seconds++;
          break;
        }
      }
      
    //   for(auto a : tracker){
    //     cout << a << " ";
    //   }
    //   cout << endl;
    }

    return seconds;
    */
  }