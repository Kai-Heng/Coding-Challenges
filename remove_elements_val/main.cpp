#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

int removeElement(vector<int>& nums, int val) {
    // 1. Swap the element that equal val at the beginning of the array
    // 2. Use two-pointer to go swap the elements

    /**
    Test case 1: val = 2, 1,2,3
    Test case 2; val = 2, 2,2,2,2,2,2
    Test case 3; val = 1, 2,3,4
    */

    int counter = 0; // to track how many elements in array equal to val

    int left = 0;
    int right = nums.size()-1;

    while(left <= right){
        if(left == right){
            if(nums[left] == val){
                counter++;
            }
        }
        else{
            while(right >= 0 && nums[right] == val){
                counter++;
                right--;
            }

            while(left < nums.size() && nums[left] != val){
                left++;
            }

            if(left < right){
                swap(nums[left], nums[right]);
                counter++;
            }
        }
        left++;
        right--;
    }

    return nums.size()-counter;
}