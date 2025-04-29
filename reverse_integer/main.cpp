#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <set>
#include <random>
#include <stack>

using namespace std;

long long reverse(long long x) {
    string i = "";
    bool isLeading = true;
    if(x < 0){
        i += "-";
        string temp = to_string(x);
        for(long long k = temp.length()-1; k >= 1; k--){
            if(temp[k] == 0 && isLeading) continue;
            i += temp[k];
            isLeading = false;
        }
    }
    else{
        string temp = to_string(x);
        for(long long k = temp.length()-1; k >= 0; k--){
            if(temp[k] == 0 && isLeading) continue;
            i += temp[k];
            isLeading = false;
        }
    }

    if(stoll(i) > INT_MAX || stoll(i) < INT_MIN){
        return 0;
    }

    return stoll(i);
}