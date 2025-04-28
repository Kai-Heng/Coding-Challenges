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

string convert(string s, int numRows) {
    bool twist = false;
    int mover = 0;
    string converted = "";
    vector<string> rows(numRows);

    if(numRows == 1){
        return s;
    }

    for(int i = 0; i < s.length(); i++){
        
        rows[mover] += s[i];

        if(!twist){
            mover++;
        }
        else{
            mover--;
        }

        if(mover >= numRows){
            twist = true;
            mover = numRows - 2;
        }
        else if(mover < 0){
            twist = false;
            mover = 1;
        }

    }

    for(auto s : rows){
        converted += s;
    }
    return converted;
}