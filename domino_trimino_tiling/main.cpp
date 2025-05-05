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

using namespace std;

int numTilings(int n) {
    const long long MOD = pow(10,9) + 7;
    if (n == 0) return 1;
    if (n == 1) return 1;
    if (n == 2) return 2;

    long long f0 = 1;       // F(0)
    long long f1 = 1;       // F(1)
    long long f2 = 2;       // F(2)

    for (int i = 3; i <= n; ++i) {
        long long fi = (2 * f2 + f0) % MOD;   // F(i) = 2*F(i-1)+F(i-3)
        f0 = f1;
        f1 = f2;
        f2 = fi;
    }
    return static_cast<int>(f2);
}