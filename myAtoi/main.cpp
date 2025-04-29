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

using namespace std;

int myAtoi(string s) {
    int i = 0, n = s.length();
    while (i < n && s[i] == ' ') i++; // skip leading spaces

    int sign = 1;
    if (i < n && (s[i] == '-' || s[i] == '+')) {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    long long num = 0;
    while (i < n && isdigit(s[i])) {
        num = num * 10 + (s[i] - '0');
        if (num * sign >= INT_MAX) return INT_MAX;
        if (num * sign <= INT_MIN) return INT_MIN;
        i++;
    }

    return (int)(num * sign);
}