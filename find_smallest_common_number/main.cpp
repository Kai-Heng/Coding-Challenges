#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <numeric>

using namespace std;


int smallest_number(int n){
    int smallest_number = 1;
    vector<int> factors(n);
    iota(factors.begin(), factors.end(), 1);
    
    // Use LCM
    for(int i = 0; i < n; i++){
        if(factors[i] == 1){
            continue;
        }
        smallest_number *= factors[i];
        int temp = factors[i];
        for(int j = i; j < n; j++){
            if(factors[j] % temp == 0){
                factors[j] = factors[j]/temp;
            }
        }
    }
    
    return smallest_number;
}