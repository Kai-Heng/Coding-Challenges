#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

const int MAX_LIMIT = 1e7 + 5;
vector<long long> prime_sum(MAX_LIMIT);

void precompute(int limit) {
    bitset<MAX_LIMIT> isPrime;
    isPrime.set(); // all true initially
    isPrime[0] = isPrime[1] = 0;

    for (int p = 2; p * p <= limit; ++p) {
        if (isPrime[p]) {
            for (int i = p * p; i <= limit; i += p)
                isPrime[i] = false;
        }
    }

    for (int i = 2; i <= limit; ++i) {
        prime_sum[i] = prime_sum[i - 1] + (isPrime[i] ? i : 0);
    }
}

int main() {
    int q;
    cin >> q;

    vector<int> queries(q);
    int max_query = 0;
    for (int i = 0; i < q; ++i) {
        cin >> queries[i];
        max_query = max(max_query, queries[i]);
    }

    precompute(max_query);

    for (int i = 0; i < q; ++i) {
        cout << prime_sum[queries[i]] << '\n';
    }

    return 0;
}