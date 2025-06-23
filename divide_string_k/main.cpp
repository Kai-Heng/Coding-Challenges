#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <unordered_map>
#include <numeric>
#include <algorithm>
#include <math.h>

using namespace std;

vector<string> divideString(string s, int k, char fill) {
    vector<string> ans;
    int curr = 0;  // starting index of each group
    // split string
    while (curr < s.length()) {
        ans.push_back(s.substr(curr, k));
        curr += k;
    }
    // try to fill in the last group
    ans.back() += string(k - ans.back().length(), fill);

    return ans;
}