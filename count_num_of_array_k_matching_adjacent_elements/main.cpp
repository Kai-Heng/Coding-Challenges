#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <unordered_map>
#include <numeric>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
    static constexpr long long MOD = 1'000'000'007;

    long long modPow(long long a, long long e) const {
        long long res = 1;
        while (e) {
            if (e & 1) res = res * a % MOD;
            a = a * a % MOD;
            e >>= 1;
        }
        return res;
    }

public:
    int countGoodArrays(int n, int m, int k) {
        if (k >= n) return 0;

        /* factorials and inverse factorials up to n-1 */
        std::vector<long long> fact(n), invFact(n);
        fact[0] = 1;
        for (int i = 1; i < n; ++i) fact[i] = fact[i - 1] * i % MOD;
        invFact[n - 1] = modPow(fact[n - 1], MOD - 2);      // Fermat
        for (int i = n - 2; i >= 0; --i)
            invFact[i] = invFact[i + 1] * (i + 1) % MOD;

        auto C = [&](int N, int R) -> long long {
            if (R < 0 || R > N) return 0;
            return fact[N] * invFact[R] % MOD * invFact[N - R] % MOD;
        };

        long long comb   = C(n - 1, k);
        long long powVal = modPow(m - 1, n - 1 - k);

        long long ans = 1LL * m * comb % MOD * powVal % MOD;
        return int(ans);
    }
};
