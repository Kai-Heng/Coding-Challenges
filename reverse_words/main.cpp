#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <stack>
#include <sstream>

using namespace std;

string reverseWords(string s) {
    stringstream ss(s);
    string word;
    string reversed_string = "";
    stack<string> st;
    while(ss >> word){
        st.push(word);
    }  

    while(!st.empty()){
        if(st.size() > 1){
            reversed_string.append(st.top() + " ");
        }
        else{
            reversed_string.append(st.top());
        }
        
        st.pop();
    }


    return reversed_string;
}