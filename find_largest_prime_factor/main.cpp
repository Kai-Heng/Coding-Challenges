#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <sstream>

using namespace std;

long max_prime_factor(long n) {
    long max_prime = -1;

    // Divide out the factor 2
    while (n % 2 == 0) {
        max_prime = 2;
        n /= 2;
    }

    // Try odd factors from 3 up
    for (long i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            max_prime = i;
            n /= i;
        }
    }

    // If what's left is a prime number > 2
    if (n > 2)
        max_prime = n;

    return max_prime;
}