#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <deque>
#include <unordered_set>

using namespace std;

void separateNumbers(string s) {
    int bl = 1;
    bool f = false;
    while(bl * 2 <= s.size()){
        string base = s.substr(0, bl);
        string newString = "";
        long baselong = atol(base.c_str());
        do{
            newString += to_string(baselong);
            baselong++;
        }while(newString.size() < s.size());
        if(newString == s) {cout << "YES " << base;f = true;break;}
        bl++;
    }
    
    if(!f) cout << "NO";
    cout << endl;
}