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

int maxArea(vector<int>& height) {
    int left = 0, right = height.size() - 1, maxArea = 0;

    while (left < right) {
        maxArea = max(maxArea, min(height[left], height[right]) * (right - left));
        if (height[left] < height[right]) left++;
        else right--;
    }

    return maxArea;
}