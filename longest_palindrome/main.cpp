#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <unordered_set>
#include <sstream>
#include <queue>

using namespace std;

string longestPalindrome(string s) {
    if (s.empty()) return "";

    int start = 0, maxLen = 1;

    for (int i = 0; i < s.size(); ++i) {
        // Odd length palindromes
        int left = i, right = i;
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            if (right - left + 1 > maxLen) {
                start = left;
                maxLen = right - left + 1;
            }
            --left;
            ++right;
        }

        // Even length palindromes
        left = i, right = i + 1;
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            if (right - left + 1 > maxLen) {
                start = left;
                maxLen = right - left + 1;
            }
            --left;
            ++right;
        }
    }

    return s.substr(start, maxLen);
}