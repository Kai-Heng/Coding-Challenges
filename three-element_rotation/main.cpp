#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

string larrysArray(vector<int> A) {
    int inversions = 0;
    int n = A.size();

    // Count the number of inversions
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i] > A[j]) inversions++;
        }
    }

    // If inversion count is even, return YES, else return NO
    return (inversions % 2 == 0) ? "YES" : "NO";
}