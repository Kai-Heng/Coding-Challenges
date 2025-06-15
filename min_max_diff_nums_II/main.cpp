#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <unordered_map>
#include <numeric>
#include <algorithm>
#include <math.h>

using namespace std;

int maxDiff(int num) {
    string num_str = to_string(num);
    string max_num, min_num;
    char leading_num;
    char leading_num_min;
    bool leading_zero = false;
    

    int i = 0;
    int j = 0;
    while(i < num_str.length() && num_str[i] == '9'){
        i++;
    }

    while(j < num_str.length() && (num_str[j] == '1' || num_str[j] == '0')){
        j++;
    }
    if(i >= num_str.length())
        leading_num = num_str[i-1];
    else{
        leading_num = num_str[i];
    }

    if(j == 0){
        leading_zero = true;
    }
    leading_num_min = num_str[j];

    for(int k = 0; k < num_str.length(); k++){
        if(num_str[k] == leading_num){
            max_num += '9';
        }
        else{
            max_num += num_str[k];
        }

        if(num_str[k] == leading_num_min && !leading_zero){
            min_num += '0';
        }
        else if(num_str[k] == leading_num_min && leading_zero){
            min_num += '1';
        }
        else{
            min_num += num_str[k];
        }
    }

    return stoll(max_num) - stoll(min_num);
}