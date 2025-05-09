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

string fractionToDecimal(int numerator, int denominator) {
    if (numerator == 0) return "0";
    
    string result;

    // Handle sign
    if ((numerator < 0) ^ (denominator < 0)) result += "-";

    // Convert to long to prevent overflow (e.g., INT_MIN)
    long long n = abs((long long)numerator);
    long long d = abs((long long)denominator);

    // Integer part
    result += to_string(n / d);
    long long rem = n % d;
    if (rem == 0) return result;

    result += ".";

    // Map from remainder to its position in result
    unordered_map<long long, int> seen;

    while (rem) {
        if (seen.count(rem)) {
            result.insert(seen[rem], "(");
            result += ")";
            break;
        }

        seen[rem] = result.size();
        rem *= 10;
        result += to_string(rem / d);
        rem %= d;
    }

    return result;
}