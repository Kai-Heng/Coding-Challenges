/**
 * Question 1. A function is given a decimal number num in string form (so str("12345")) and an integer parameter k. 
 * A number is said to be attractive if all digits of num that are k units apart are equal. So, num[i] = num[i+k] for 0<=i<(n-k). 
 * For example, "25252" for k=2 would be an attractive number. So will 43214 for k=4, but "25352" for k=2 is not an attractive number. 
 * Given a string num and a parameter k, our job is to find the smallest attractive number greater than or equal to num.
 * 
 * Question 2. We are given an array cost with cost of different items. A package can contain at most two items.
 * The cost of the package is equal to the sum of the item(s) it contains. 
 * For any given distribution, an item can only be in one package (i.e, when distributing items in different packages, an item can only be in one package). 
 * What is the maximum number of packages that can be produced for a given cost array, such that all the packages have the same cost. 
 * (Remember the constraint that a package must have at least one, and at most two items). 
 */
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

string check_attractive(string s, int k){
    map<char,int> unique_num;
    for(int i = 0; i < s.length(); i++){
        if(unique_num.count(s[i]) == 0){
            unique_num.insert(pair<char,int>(s[i], 1));
        }
    }

    for(int i = 0; i < unique_num.size(); i++){
        for(int j = i; j < s.length(); j+=k){
            if(s[i] != s[j]){
                return "Not Attractive";
            }
        }
    }

    return "Attarctive";
}

int main(){
    string s = "25352";
    int k = 2;
    cout << check_attractive(s, k) << endl;
}