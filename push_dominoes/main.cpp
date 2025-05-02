#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <set>
#include <random>

using namespace std;

string pushDominoes(string dominoes) {
    int n = dominoes.size();
    // pad with sentinels
    string s = "L" + dominoes + "R";
    int prev = 0;                      // index of last non-'.'

    for (int cur = 1; cur < s.size(); ++cur) {
        if (s[cur] == '.') continue;   // still inside a dot block

        // we now have s[prev] .... s[cur]
        if (s[prev] == s[cur]) {
            // same direction → fill entire gap
            for (int k = prev + 1; k < cur; ++k) s[k] = s[cur];
        } else if (s[prev] == 'R' && s[cur] == 'L') {
            // opposing forces → meet in the middle
            int l = prev + 1, r = cur - 1;
            while (l < r) { s[l++] = 'R'; s[r--] = 'L'; }
            // middle char (if any) stays '.'
        }
        // case L ... R → nothing changes
        prev = cur;                    // start new block
    }
    return s.substr(1, n);             // drop the sentinels
}