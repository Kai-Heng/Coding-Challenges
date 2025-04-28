#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <unordered_set>
#include <sstream>
#include <queue>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int new_size = nums1.size() + nums2.size();
    int m_idx = 0;
    bool isOdd = false;
    vector<int> newArr;
    if(new_size % 2 == 1){
        isOdd = true;
    }
    int i1 = 0;
    int i2 = 0;
    while(i1 < nums1.size() && i2 < nums2.size()){
        if(nums1[i1] <= nums2[i2]){
            newArr.push_back(nums1[i1]);
            i1++;
        }
        else if(nums1[i1] > nums2[i2]){
            newArr.push_back(nums2[i2]);
            i2++;
        }

        if(isOdd && i1+i2 > new_size/2){
            return newArr.back();
        }
        else if(!isOdd && i1+i2 > new_size/2){
            return double(newArr.back()+newArr[newArr.size()-2])/2.0;
        }
    }

    while(i1 < nums1.size()){
        newArr.push_back(nums1[i1]);
        i1++;

        if(isOdd && i1+i2 > new_size/2){
            return newArr.back();
        }
        else if(!isOdd && i1+i2 > new_size/2){
            return double(newArr.back()+newArr[newArr.size()-2])/2.0;
        }
    }

    while(i2 < nums2.size()){
        newArr.push_back(nums2[i2]);
        i2++;

        if(isOdd && i1+i2 > new_size/2){
            return newArr.back();
        }
        else if(!isOdd && i1+i2 > new_size/2){
            return double(newArr.back()+newArr[newArr.size()-2])/2.0;
        }
    }
    return 0;
}