#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <sstream>

using namespace std;

long long sum_of_multiples(int num, int n){
    long long k = (n-1) / num;
    return num * k * (k+1) / 2;
}

int sum_of_3_5(int n){
    // O(log n)
    /** 
    int sum = 0;
    int left = 1;
    int right = n-1;
    
    while(left <= right){
        
        if(left == right && (left % 3 == 0 || left % 5 == 0)){
            sum += left;
            break;
        }
        if(left % 3 == 0 || left % 5 == 0){
            sum += left;
        }
        
        if(right % 3 == 0 || right % 5 == 0){
            sum += right;
        }
        
        left++;
        right--;
    }

    return sum;
    */

    // O(1)
    long long sum3 = sum_of_multiples(3, n);
    long long sum5 = sum_of_multiples(5, n);
    long long sum15 = sum_of_multiples(15, n);

    
    return sum3 + sum5 - sum15;
}