#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <deque>
#include <set>

using namespace std;

long maximumSum(vector<long> a, long m) {
    long max_val = -1;
    set<long> prefixSet;
    long prefix = 0;
    int n = a.size();

    for(long i = 0; i < n; i++){
        prefix = (prefix + a[i] % m ) % m;
        max_val = max(max_val, prefix);
        
        auto it = prefixSet.upper_bound(prefix);
        if(it != prefixSet.end()){
            max_val = max(max_val, (prefix - *it + m) % m);
        }
        
        prefixSet.insert(prefix);
    }
    
    return max_val;
}