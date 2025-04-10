#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

vector<long> bonetrousle(long n, long k, int b) {
    vector<long> result;
    
    long min_sum = (long)b * (b + 1) / 2;
    long max_sum = (long)b * (2 * k - b + 1) / 2;

    if (n < min_sum || n > max_sum) {
        result.push_back(-1);
        return result;
    }

    // Initialize with the smallest possible b values: [1, 2, ..., b]
    vector<long> boxes(b);
    for (int i = 0; i < b; i++) {
        boxes[i] = i + 1;
    }

    long diff = n - min_sum;

    // Try to push values higher from the rightmost side while keeping uniqueness and <= k
    for (int i = b - 1; i >= 0 && diff > 0; i--) {
        long max_val = k - (b - 1 - i);  // max we can set for this position
        long increment = min(diff, max_val - boxes[i]);
        boxes[i] += increment;
        diff -= increment;
    }

    return boxes;
}