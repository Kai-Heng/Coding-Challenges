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

int romanToInt(string s) {
    unordered_map<string, int> valueSymbols = {
        {"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400},
        {"C", 100},  {"XC", 90},  {"L", 50},  {"XL", 40},
        {"X", 10},   {"IX", 9},   {"V", 5},   {"IV", 4},
        {"I", 1}
    };

    int num = 0;

    for(int i = 0; i < s.length(); i++){
        if(i+1 < s.length() && valueSymbols[string(1,s[i])] < valueSymbols[string(1,s[i+1])]){
            string temp = string(1,s[i]) + string(1,s[i+1]);
            num += valueSymbols[temp];
            cout << num << endl;
            i++;
        }
        else{
            num += valueSymbols[string(1, s[i])];
        }
    }

    return num;
}