#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

int countSwaps(vector<int> arr, vector<int> sortedArr) {
    int n = arr.size();
    unordered_map<int, int> posMap;
    for (int i = 0; i < n; i++) {
        posMap[sortedArr[i]] = i;  // Map value to its sorted position
    }

    vector<bool> visited(n, false);
    int swaps = 0;

    for (int i = 0; i < n; i++) {
        if (visited[i] || posMap[arr[i]] == i) continue;  // Skip already sorted elements

        int cycleSize = 0;
        int j = i;

        while (!visited[j]) {
            visited[j] = true;
            j = posMap[arr[j]];  // Move to correct index in sorted array
            cycleSize++;
        }

        if (cycleSize > 1) {
            swaps += (cycleSize - 1);  // Minimum swaps for cycle
        }
    }
    return swaps;
}

// Function to determine the minimum swaps needed to make the array beautiful
int lilysHomework(vector<int> arr) {
    vector<int> arrAsc = arr;
    vector<int> arrDesc = arr;

    sort(arrAsc.begin(), arrAsc.end());  // Ascending order
    sort(arrDesc.begin(), arrDesc.end(), greater<int>());  // Descending order

    return min(countSwaps(arr, arrAsc), countSwaps(arr, arrDesc));  // Minimum swaps needed
}