#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <sstream>

using namespace std;

string isBalanced(string s) {
    
    if(s.length() % 2 == 1){
        return "NO";
    }
    vector<char> stack;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            stack.push_back(s[i]);
        }
        else{
            if(stack.empty()){
                return "NO";
            }
            if((int)stack[stack.size()-1] == int(s[i]) - 2 || (int)stack[stack.size()-1] == int(s[i]) - 1){
                stack.pop_back();
            }
            else{
                return "NO";
            }
        }
    }
    
    if(!stack.empty()){
        return "NO";
    }
    
    return "YES";
}