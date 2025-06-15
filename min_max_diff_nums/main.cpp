#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <unordered_map>
#include <numeric>
#include <algorithm>
#include <math.h>

using namespace std;

int minMaxDifference(int num) {
    string num_str = to_string(num);
    string max_num, min_num;
    char leading_num = 'a';
    char leading_num_min = 'a';
    for(int i = 0; i < num_str.length(); i++){
        if(leading_num == 'a' && num_str[i] != '9'){
            leading_num = num_str[i];
            max_num += '9';
            cout << leading_num << " ";
        }
        else{
            if(num_str[i] == leading_num){
                max_num += '9';
            }
            else{
                max_num += num_str[i];
            }
        }

        if(leading_num_min == 'a' && num_str[i] != '0'){
            leading_num_min = num_str[i];
            min_num += '0';
        }
        else{
            if(num_str[i] == leading_num_min){
                min_num += '0';
            }
            else{
                min_num += num_str[i];
            }
        }
    }

    return stoll(max_num) - stoll(min_num);
}