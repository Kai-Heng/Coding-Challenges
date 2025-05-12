#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <set>

using namespace std;

long long minSum(vector<int>& nums1, vector<int>& nums2) {
    long long num1_0 = 0;
    long long num2_0 = 0;
    long long sum1 = 0, sum2 = 0;
    for(int i = 0; i < nums1.size(); i++){
        if(nums1[i] == 0){
            num1_0++;
            sum1++;
        }
        else{
            sum1 += nums1[i];
        }
    }

    for(int i = 0; i < nums2.size(); i++){
        if(nums2[i] == 0){
            num2_0++;
            sum2++;
        }
        else{
            sum2 += nums2[i];
        }
    }

    if(sum1 == sum2){
        return sum1;
    }

    if(sum1 < sum2){
        if(num1_0 == 0) return -1;
        return sum2;
    }
    else{
        if(num2_0 == 0) return -1;
        return sum1;
    }
}