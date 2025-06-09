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

class Solution {
private:
    long long count(long long prefix, long long n) {
        long long cur = prefix, next = prefix + 1, cnt = 0;
        while (cur <= n) {
            cnt += std::min(n + 1LL, next) - cur;   // nodes in this layer
            cur *= 10;
            next *= 10;
        }
        return cnt;
    }
public:
    int findKthNumber(int n, int k) {
        long long cur = 1;          // first number in lexicographical order
        --k;                        // we are already at 1

        while (k > 0) {
            long long step = count(cur, n);
            if (step <= k) {        // k-th number is not in this subtree
                ++cur;              // move to next sibling
                k -= step;
            } else {                // go deeper into the current subtree
                cur *= 10;          // first child
                --k;
            }
        }
        return (int)cur;
    }
};