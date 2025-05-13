#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

int lengthAfterTransformations(string s, int t) {
    const int MOD = 1e9 + 7;
    vector<long long> freq(26, 0);

    for (char c : s)
        freq[c - 'a']++;

    while (t--) {
        vector<long long> nextFreq(26, 0);

        for (int i = 0; i < 26; ++i) {
            if (i == 25) { // 'z' → "ab"
                nextFreq[0] = (nextFreq[0] + freq[i]) % MOD;
                nextFreq[1] = (nextFreq[1] + freq[i]) % MOD;
            } else {
                nextFreq[i + 1] = (nextFreq[i + 1] + freq[i]) % MOD;
            }
        }

        freq = nextFreq;
    }

    long long total = 0;
    for (int i = 0; i < 26; ++i)
        total = (total + freq[i]) % MOD;

    return total;
}