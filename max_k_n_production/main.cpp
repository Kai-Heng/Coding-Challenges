#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <sstream>

using namespace std;

long long max_n_production(int k, int n, string num){
    long long max_production = -INFINITY;
    
    int i = 0;
    while(i+k <= n){
        long long product = 1;
        for(int j = i; j < i+k; j++){
            product *= (num[j]-'0');
        }
        max_production = max(max_production, product);
        i++;
    }
    
    return max_production;
}