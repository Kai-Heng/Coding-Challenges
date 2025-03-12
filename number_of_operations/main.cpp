/**
 * Christy is interning at HackerRank. One day she has to distribute some chocolates to her colleagues. 
 * She is biased towards her friends and plans to give them more than the others. One of the program managers 
 * hears of this and tells her to make sure everyone gets the same number.
 * 
 * To make things difficult, she must equalize the number of chocolates in a series of operations. 
 * For each operation, she can give [1,2 or 5] pieces to all but one colleague. Everyone who gets a piece in a round receives the same number of pieces.
 * 
 * Given a starting distribution, calculate the minimum number of operations needed so that every colleague has the same number of pieces.
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

int minOperations(vector<int> arr, int target) {
    int operations = 0;
    for (int num : arr) {
        int diff = num - target;
        operations += diff / 5;  // Use 5s as much as possible
        diff %= 5;
        operations += diff / 2;  // Use 2s
        diff %= 2;
        operations += diff;      // Use 1s
    }
    return operations;
}

int equal(vector<int> arr) {
    int minVal = *min_element(arr.begin(), arr.end());
    int result = INT_MAX;

    // Try reducing all elements to minVal, minVal-1, minVal-2, ..., minVal-4
    for (int i = 0; i < 5; i++) {
        result = min(result, minOperations(arr, minVal - i));
    }

    return result;
}