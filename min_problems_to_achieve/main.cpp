#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

int getMinProblemCount(int N, vector<int> S) {
    // Write your code here
    sort(S.begin(), S.end());
    
    int min_problems = 0;
    for(int i = 0; i < N; i++){
      if(S[i]%2 == 1){
        min_problems++;
        break;
      }
    }
    
    long long divide = S[S.size()-1]/2;
    
    
    min_problems += divide;
    
    return min_problems;
  }