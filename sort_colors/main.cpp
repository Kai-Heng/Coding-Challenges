#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

void sortColors(vector<int>& nums) {
    for(int i = 0; i < nums.size()-1; i++){
        if(nums[i] > nums[i+1]){
            for(int j = i+1; j >= 1; j--){
                if(nums[j] < nums[j-1]){
                    swap(nums[j], nums[j-1]);
                }
            }
        }
    }
}