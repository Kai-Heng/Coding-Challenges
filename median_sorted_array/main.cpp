#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();
    int total = n + m;

    vector<int> merged;
    int i = 0, j = 0;

    // Merge both arrays
    while (i < n && j < m) {
        if (nums1[i] < nums2[j]) {
            merged.push_back(nums1[i++]);
        } else {
            merged.push_back(nums2[j++]);
        }
    }

    while (i < n) merged.push_back(nums1[i++]);
    while (j < m) merged.push_back(nums2[j++]);

    // Find median
    if (total % 2 == 1) {
        return merged[total / 2];
    } else {
        return (merged[total / 2 - 1] + merged[total / 2]) / 2.0;
    }
}