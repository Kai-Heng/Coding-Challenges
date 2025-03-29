#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <sstream>

using namespace std;

vector<int> generatePrimes(int limit) {
    vector<bool> isPrime(limit + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int p = 2; p * p <= limit; ++p) {
        if (isPrime[p]) {
            for (int i = p * p; i <= limit; i += p) {
                isPrime[i] = false;
            }
        }
    }
    
    vector<int> primes;
    for (int i = 2; i <= limit; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

int find_nth_prime(int n) {
    if (n <= 0) {
        return -1;
    }
    if (n == 1) {
        return 2;
    }
    int limit = 10; // Initial limit
    std::vector<int> primes;
    while (true) {
        primes = generatePrimes(limit);
        if (primes.size() >= n) {
            return primes[n - 1];
        }
        limit *= 2; // Double the limit and try again
    }
}