#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <set>
using namespace std;


int main() {
    unsigned long long n, s, p, q;
    cin >> n >> s >> p >> q;

    const unsigned long long MOD = 1ULL << 31;
    unsigned long long a0 = s % MOD;
    unsigned long long a = a0;
    unsigned long long ap = 0;
    unsigned long long k = 0;

    for (unsigned long long i = 0; i < n; i++) {
        a = (a * p + q) % MOD;

        // If the value repeats (either matches start or previous), break
        if ((a == a0 || a == ap) && i != 0) {
            k = i + 1;
            break;
        }

        ap = a;
    }

    if (k == 0) k = n; // No cycle found in range

    cout << k << endl;
    
    return 0;
}
