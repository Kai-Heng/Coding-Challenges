#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

string highestValuePalindrome(string s, int n, int k) {
    vector<bool> changed(n, false);
    
    // First pass: Convert to palindrome with minimal changes
    int left = 0, right = n - 1;
    int changes = 0;

    while (left < right) {
        if (s[left] != s[right]) {
            s[left] = s[right] = max(s[left], s[right]); // Make them the same
            changed[left] = changed[right] = true; // Mark as changed
            changes++;
        }
        left++;
        right--;
    }

    // If we need more changes than k, return -1
    if (changes > k) {
        return "-1";
    }

    // Second pass: Maximize the palindrome value (making as many 9s as possible)
    left = 0, right = n - 1;
    int remaining = k - changes; // Remaining changes after ensuring palindrome

    while (left <= right) {
        if (left == right && remaining > 0) { 
            // If there's a middle character (odd length), maximize it
            s[left] = '9';
        }

        if (s[left] != '9') {
            if (changed[left] && remaining > 0) {
                // If it was changed before, we need only 1 more change
                s[left] = s[right] = '9';
                remaining--;
            } 
            else if (!changed[left] && remaining >= 2) {
                // If it wasn't changed before, we need 2 changes
                s[left] = s[right] = '9';
                remaining -= 2;
            }
        }

        left++;
        right--;
    }

    return s;
}