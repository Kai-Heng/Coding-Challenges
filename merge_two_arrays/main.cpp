#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    if(n == 0){
        return;
    }

    if(m == 0){
        nums1 = nums2;
        return;
    }

    int left = 0;
    int right = 0;
    int track_m = 0;
    
    while(left < m+n && right < n){
        if(track_m < m && nums1[left] < nums2[right]){
            left++;
            track_m++;
        }
        else{
            nums1.insert(nums1.begin()+left, nums2[right]);
            nums1.pop_back();
            left++;
            right++;
        }
    }
}