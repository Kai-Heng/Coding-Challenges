#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <sstream>
#include <queue>

using namespace std;

long repeatedString(string s, long n) {
    long a_freq = 0;
    
    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'a')
            a_freq++;
    }
    
    if(a_freq == 0){
        return a_freq;
    }

    long remainder = n % s.length();
    long divide = n / s.length();
    
    int a_remainder_count = 0;
    for(int i = 0; i < remainder; i++){
        if(s[i] == 'a'){
            a_remainder_count++;
        }
    }
    
    return divide * a_freq + a_remainder_count;
}