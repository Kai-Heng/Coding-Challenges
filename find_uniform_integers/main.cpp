#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

vector<long long> findAllUniformIntegers(){
    vector<long long> uniform;
    for(long long i = 1; i <= 9; i++){
      uniform.push_back(i);
    }
    
    long long num = 11;
    int factor = 1;
    while(num < 1e12){
      uniform.push_back(num * factor);
      
      factor++;
      if(factor > 9){
        num = num*10 + 1;
        factor = 1;
      }
    }
    
    return uniform;
  }
  
  int getUniformIntegerCountInInterval(long long A, long long B) {
    // Write your code here
    vector<long long> all_uniform = findAllUniformIntegers();
    
    auto lower = lower_bound(all_uniform.begin(), all_uniform.end(), A);
    auto upper = upper_bound(all_uniform.begin(), all_uniform.end(), B);
    
    return distance(lower,upper);
  }