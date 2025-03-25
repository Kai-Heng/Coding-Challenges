#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <sstream>

using namespace std;

bool isPalindrom(int n){
    string n_str = to_string(n);
    int left = 0;
    int right = n_str.length()-1;
    
    while(left < right){
        if(n_str[left] != n_str[right]){
            return false;
        }
        
        left++;
        right--;
    }
    
    return true;
}

bool isProductOfThreeDigits(int n){
    for(int i = 999; i >= 100; i--){
        if(n % i == 0 && (n/i >= 100 && n / i <= 999)){
            return true;
        }
    }
    
    return false;
}

int max_palindrome_product(int n){
    for(int i = n; i >= 0; i--){
        if(isPalindrom(i) && isProductOfThreeDigits(i) && i < n){
            return i;
        }
    }
    
    return 1;
}