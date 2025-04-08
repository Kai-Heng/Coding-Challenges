#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

int chocolateFeast(int n, int c, int m) {
    int count = 0;
    int purchased = n / c;
    int trade_in = purchased / m;
    int remainder_wrapper = purchased % m;
    
    int wrappers = remainder_wrapper + trade_in;
    count = purchased + trade_in;
    while(wrappers >= m){
        remainder_wrapper = wrappers % m;
        wrappers = wrappers/m;
        count += wrappers;
        wrappers += remainder_wrapper;
    }
    
    return count;
}