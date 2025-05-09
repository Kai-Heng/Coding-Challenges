#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <set>
#include <random>
#include <stack>
#include <unordered_set>
#include <queue>

using namespace std;

int maxRepOpt1(string text) {
    int n = text.size();
    array<int, 26> freq = {};
    for (char ch : text) ++freq[ch - 'a'];

    int ans = 0;
    for (int c = 0; c < 26; ++c) {
        int left = 0, bad = 0;
        for (int right = 0; right < n; ++right) {
            if (text[right] - 'a' != c) ++bad;
            while (bad > 1) {
                if (text[left] - 'a' != c) --bad;
                ++left;
            }
            int len = right - left + 1;
            bool has_extra = freq[c] > (len - bad);
            ans = max(ans, len - (bad == 1 && !has_extra));
        }
    }
    return ans;
}