#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

bool isTriangleValid(vector<int>& nums){
    int i = 0;
    if(nums[0] + nums[1] <= nums[2]) return false;
    if(nums[0] + nums[2] <= nums[1]) return false;
    if(nums[1] + nums[2] <= nums[0]) return false;

    return true;
}
string triangleType(vector<int>& nums) {
    unordered_map<int,int> sides;

    if(!isTriangleValid(nums)) return "none";

    for(int i = 0; i < nums.size(); i++){
        sides[nums[i]]++;
    }

    if(sides.size() == 1){
        return "equilateral";
    }
    else if(sides.size() == 2){
        return "isosceles";
    }
    else{
        return "scalene";
    }
}