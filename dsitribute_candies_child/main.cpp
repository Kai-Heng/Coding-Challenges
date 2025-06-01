#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

// O(1)
static long long C2(long long n) {
    return n < 2 ? 0LL : n * (n - 1) / 2;
}

long long distributeCandies(int n, int limit) {
    long long L = limit + 1LL;          // how much we subtract when a child exceeds limit
    // impossible if we need more candies than the three limits altogether
    if (n > 3LL * limit) return 0;

    long long ways = 0;
    for (int t = 0; t <= 3; ++t) {      // t = how many kids exceed the limit
        long long rem = n - t * L;      // total left after "shaving off" those t kids
        if (rem < 0) continue;          // this term contributes 0

        long long comb3t = (t == 0 ? 1LL : (t == 3 ? 1LL : 3LL));  // C(3, t)
        long long term   = comb3t * C2(rem + 2);                   // C(rem+2, 2)

        ways += (t & 1 ? -term : term);  // alternating signs
    }
    return ways;
}

// O(limit)
long long distributeCandies(int n, int limit) {
    long long ways = 0;
    for (int a = max(0, n - 2*limit); a <= min(limit, n); ++a) {
        int sum = n - a;          // need b + c = sum

        if (sum <= limit) {       // 0 … limit, both vars free
            ways += sum + 1;      // (0, sum) … (sum, 0)
        } else {                  // limit < sum ≤ 2*limit
            // b must be ≥ sum-limit and ≤ limit
            ways += 2*limit - sum + 1;
        }
    }
    return ways;
}