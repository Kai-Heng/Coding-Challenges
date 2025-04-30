#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <set>
#include <random>
#include <stack>

using namespace std;

long long countSubarrays(vector<int>& nums, int k) {
    int n = nums.size();
    int maxVal = *max_element(nums.begin(), nums.end());
    long long result = 0;
    int count = 0;
    int left = 0;

    for (int right = 0; right < n; ++right) {
        if (nums[right] == maxVal) {
            count++;
        }

        while (count >= k) {
            result += (n - right); // all subarrays [left...right], [left...right+1], ... are valid
            if (nums[left] == maxVal) {
                count--;
            }
            left++;
        }
    }

    return result;
}