#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

int steadyGene(string gene) {
    int n = gene.length();
    int target = n / 4; // Each character should appear exactly n/4 times
    unordered_map<char, int> freq;

    // Step 1: Count initial frequencies of C, G, A, T
    for (char c : gene) {
        freq[c]++;
    }

    // Step 2: Identify if the string is already steady
    bool alreadySteady = true;
    for (char c : "CGAT") {
        if (freq[c] > target) {
            alreadySteady = false;
        }
    }
    if (alreadySteady) return 0; // No need to replace anything

    // Step 3: Use a sliding window approach to find the minimum substring
    int left = 0, minLength = n;
    for (int right = 0; right < n; ++right) {
        freq[gene[right]]--; // Expand window (reduce freq of character on right)

        // Try to shrink the window from the left if it's still valid
        while (left < n && freq['C'] <= target && freq['G'] <= target && 
               freq['A'] <= target && freq['T'] <= target) {
            minLength = min(minLength, right - left + 1);
            freq[gene[left]]++; // Shrink window from left
            left++;
        }
    }

    return minLength;
}